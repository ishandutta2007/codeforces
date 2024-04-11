#include <iostream>

using namespace std;

int n;
string s;
string x[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < 8; i++) {
        if (x[i].size() != n) continue;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (x[i][j] == s[j]) continue;
            if (s[j] == '.') continue;
            ok = false;
        }
        if (ok) cout << x[i] << "\n";
    }
}