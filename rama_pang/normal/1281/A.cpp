#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (string(s.end() - 2, s.end()) == "po") {
            cout << "FILIPINO\n";
        } else if (string(s.end() - 4, s.end()) == "desu") {
            cout << "JAPANESE\n";
        } else if (string(s.end() - 4, s.end()) == "masu") {
            cout << "JAPANESE\n";
        } else if (string(s.end() - 5, s.end()) == "mnida") {
            cout << "KOREAN\n";
        }
    }
}