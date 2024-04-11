#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if (s.length() & 1) {
            bool there = false;
            for (int i = 0; i < n; i += 2) {
                if ((s[i] - '0') & 1) {
                    there = true;
                }
            }
            cout << (there ? 1 : 2) << '\n';
        } else {
            bool there = false;
            for (int i = 1; i < n; i += 2) {
                if (!((s[i] - '0') & 1)) {
                    there = true;
                }
            }
            cout << (there ? 2 : 1) << '\n';
        }
    }
    return 0;
}