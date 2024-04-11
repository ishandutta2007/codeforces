#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool f = 0;
        for (int u : s) {
            if (u == '>') {
                f = 1;
                break;
            }
        }
        if (!f) {
            cout << n << '\n';
            continue;
        }
        f = 0;
        for (int u : s) {
            if (u == '<') {
                f = 1;
                break;
            }
        }
        if (!f) {
            cout << n << '\n';
                continue;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int prev = (i + n - 1) % n;
            if (s[i] == '-' || s[prev] == '-') res++;
        }
        cout <<  res << '\n';
    }
    return 0;
}