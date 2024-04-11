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
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<int> pref(n), p(m);
        for (int i = 0; i < m; i++) cin >> p[i], --p[i];

        for (int i = 0; i < m; i++)
            pref[p[i] + 1]--;

        vector<int> ans(26);
        int cur = m + 1;

        for (int i = 0; i < n; i++) {
            cur += pref[i];
            ans[s[i] - 'a'] += cur;
        }

        for (int i = 0; i < 26; i++) cout << ans[i] << " \n"[i + 1 == 26];
    }
    return 0;
}