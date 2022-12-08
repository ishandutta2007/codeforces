#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t-->0) {
        int n; cin >> n;
        string d; cin >> d;

        vector<int> mn(n), ans(n);
        mn[n - 1] = d[n - 1] - '0';
        for (int i = n - 2; i >= 0; --i) {
            mn[i] = min(mn[i + 1], d[i] - '0');
        }
        for (int i = 0; i < n - 1; ++i) {
            if (d[i] - '0' > mn[i + 1]) {
                ans[i] = 2;
            }
        }

        vector<int> mx(n);
        mx[0] = d[0] - '0';
        for (int i = 1; i < n; ++i) {
            mx[i] = max(mx[i - 1], d[i] - '0');
        }
        for (int i = 1; i < n; ++i) {
            if (d[i] - '0' < mx[i - 1]) {
                ans[i] = 1;
            }
        }

        int ind = -1;
        for (int i = 0; i < n; ++i) if (ans[i] == 1) {
            ind = i;
        }

        for (int i = 0; i < n; ++i) if (ans[i] == 0) {
            ans[i] = i < ind ? 1 : 2;
        }

        string cur = "";
        for (int i = 0; i < n; ++i) if (ans[i] == 1) {
            cur += d[i];
        }
        for (int i = 0; i < n; ++i) if (ans[i] == 2) {
            cur += d[i];
        }
        int ok = 1;
        for (int i = 1; i < n; ++i) if (cur[i] < cur[i - 1]) {
            ok = 0;
        }
        if (ok) {
            for (int i : ans) cout << i;
            cout << "\n";
        } else {
            cout << "-\n";
        }
    }
    return 0;
}