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
        string s;
        cin >> s;

        int x;
        cin >> x;

        string ans(s.length(), '1');

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                if (i - x >= 0)
                    ans[i - x] = '0';
                if (i + x < s.length())
                    ans[i + x] = '0';
            }
        }

        bool ok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                if ((i - x >= 0 and ans[i - x] == '1') or (i + x < s.length() and ans[i + x] == '1')) {

                } else {
                    ok = false;
                }
            }
        }

        cout << (ok ? ans : "-1") << "\n";
    }
    return 0;
}