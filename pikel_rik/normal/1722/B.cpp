#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        array<string, 2> s;
        for (auto &x : s) {
            cin >> x;
            for (auto &ch : x) {
                if (ch == 'G') {
                    ch = 'B';
                }
            }
        }

        cout << (s[0] == s[1] ? "YES" : "NO") << '\n';
    }
    return 0;
}