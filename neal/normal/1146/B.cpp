#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T;
    cin >> T;

    string plus = "";

    for (char c : T)
        if (c != 'a')
            plus += c;

    if (plus.size() % 2 != 0) {
        cout << ":(" << '\n';
        return 0;
    }

    int n = plus.size() / 2;

    if (plus.substr(0, n) != plus.substr(n, n)) {
        cout << ":(" << '\n';
        return 0;
    }

    for (int i = (int) T.size() - n; i < (int) T.size(); i++)
        if (T[i] == 'a') {
            cout << ":(" << '\n';
            return 0;
        }

    cout << T.substr(0, T.size() - n) << '\n';
}