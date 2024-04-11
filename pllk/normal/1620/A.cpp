#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int u = 0;
        for (auto c : s) if (c == 'N') u++;
        if (u == 1) cout << "NO\n";
        else cout << "YES\n";
    }
}