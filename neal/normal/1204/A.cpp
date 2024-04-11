#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;

    while (S.size() < 100)
        S = "0" + S;

    int count = 0;

    for (int i = 0; i < 100; i += 2) {
        string train(100, '0');
        train[i] = '1';
        reverse(train.begin(), train.end());

        if (train < S)
            count++;
    }

    cout << count << '\n';
}