#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size(), w, m;
        cin >> w >> m;
        vector<int> pr(n + 1);
        vector<vector<int>> arr(9);
        for (int i = 0; i < n; i++) {
            pr[i + 1] = pr[i] + s[i] - '0';
        }
        for (int i = w; i <= n; i++) {
            int mod = (pr[i] - pr[i - w]) % 9;
            if (arr[mod].size() < 2) {
                arr[mod].pb(i - w + 1);
            }
        }
        for (int i = 0; i < m; i++) {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            int v = (pr[r] - pr[l]) % 9;
            pair<int,int> p = {n + 1, n + 1};
            for (int a = 0; a < 9; a++) {
                for (int b = 0; b < 9; b++) {
                    if ((a * v + b) % 9 == k) {
                        for (auto f : arr[a]) {
                            for (auto s : arr[b]) {
                                if (f != s) {
                                    p = min(p, make_pair(f, s));
                                }
                            }
                        }
                    }
                }
            }
            if (p.first == n + 1) {
                cout << -1 << ' ' << -1 << endl;
            } else {
                cout << p.first << ' ' << p.second << endl;
            }
        }
    }
    return 0;
}