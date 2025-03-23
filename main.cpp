#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>

#include "merge.h"

using namespace std;

vector<int> readFromFile(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);
    if (!file) {
        cerr << "Eroare: Nu s-a putut deschide fisierul " << filename << "\n";
        return numbers; 
    }

    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
    file.close();
    return numbers;
}

int main() {
    for (int i = 1; i <= 10; ++i) {
        string inputFile = "data" + to_string(i) + ".txt";

        vector<int> data = readFromFile(inputFile);
        if (data.empty()) {
            cerr << "Fisierul " << inputFile << " este gol\n";
            continue;
        }

        auto start = chrono::high_resolution_clock::now();

        mergeSort(data, 0, data.size() - 1);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;

        cout << "Sortare finalizata pentru " << inputFile << " in " << duration.count() << " ms\n";
    }

    return 0;
}
