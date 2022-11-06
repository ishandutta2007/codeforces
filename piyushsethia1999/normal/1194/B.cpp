#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<string> s(n); for (int o = 0; o < n; o++) { cin >> s[o]; }
        std::vector<pair<int, int> > r(n);
        std::vector<pair<int, int> > c(m);
        for (int i = 0; i < n; ++i) {
            r[i] = {0, i};
        }
        for (int i = 0; i < m; ++i) {
            c[i] = {0, i};
        }
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) 
                if (s[i][j] == '*') 
                    r[i].first++, c[j].first++;
        std::vector<int> rr;
        std::vector<int> cc;
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            ma = max(ma, r[i].first);
        }
        for (int i = 0; i < n; ++i) {
            if (r[i].first == ma) rr.pb(i);
        }
        int y = n - ma;
        ma = 0;
        for (int i = 0; i < m; ++i) {
            ma = max(ma, c[i].first);
        }
        y += (m - ma);
        for (int i = 0; i < m; ++i) {
            if (c[i].first == ma) cc.pb(i);
        }
        bool ok = false;
        for (int i = 0; i < rr.size() && (!ok); ++i) {
            for (int j = 0; j < cc.size(); ++j) {
                if (s[rr[i]][cc[j]] == '.') {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) y--;
        cout << y << "\n";
    }
}