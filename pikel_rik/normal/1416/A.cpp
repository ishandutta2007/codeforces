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

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> pos(n + 1, vector<int>(1, -1));
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
        }

        vector<int> ans(n + 1, INT_MAX);
        for (int i = 1, cur = n; i <= n && cur > 0; i++) {
            pos[i].push_back(n);
            int mx = 0;
            for (int j = 1; j < pos[i].size(); j++) {
                mx = max(mx, pos[i][j] - pos[i][j - 1] - 1);
            }

            if (mx + 1 <= cur) {
                ans[mx + 1] = i;
                cur = mx;
            }
        }

        int mn = INT_MAX;
        for (int i = 1; i <= n; i++) {
            mn = min(mn, ans[i]);
            cout << (mn != INT_MAX ? mn : -1) << " \n"[i == n];
        }
    }
    return 0;
}