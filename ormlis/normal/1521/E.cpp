#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int m, k; cin >> m >> k;
    vector<pair<int, int>> have2;
    int mx = 0;
    range(i, k) {
        int c; cin >> c;
        if (c) have2.push_back({c, i + 1});
        mx = max(mx, c);
    }
    sort(rall(have2));
    for(int n = 1; n <= m; ++n) {
        ll canmx = 1ll * n * ((n + 1) / 2);
        if (canmx < mx) continue;
        ll canm = canmx + 1ll * (n / 2) * ((n + 1) / 2);
        if (canm < m) continue;
        vector<vector<int>> result(n, vector<int> (n, 0));
        list<pair<int, int>> ord;
        for(int i = 0; i < n; i += 2) {
            for(int j = 1; j < n; j += 2) {
                ord.emplace_back(i, j);
            }
        }
        for(int i = 1; i < n; i += 2) {
            for(int j = 0; j < n; j += 2) {
                ord.emplace_back(i, j);
            }
        }
        for(int i = 0; i < n; i += 2) {
            for(int j = 0; j < n; j += 2) {
                ord.emplace_back(i, j);
            }
        }
        auto check = [&] (int i, int j, int col) {
            for(int i1 = i - 1; i1 <= i + 1; i1 += 2) {
                for(int j1 = j - 1; j1 <= j + 1; j1 += 2) {
                    if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= n) continue;
                    if (result[i1][j1] == col) return false;
                }
            }
            result[i][j] = col;
            return true;
        };
        auto have = have2;
        bool ok = true;
        for(auto &[cnt, col] : have) {
            auto it = ord.begin();
            range(_, cnt) {
                bool good = false;
                while(it != ord.end()) {
                    if (check(it->first, it->second, col)) {
                        it = ord.erase(it);
                        good = true;
                        break;
                    }
                    it++;
                }
                ok &= good;
            }
        }
        if (!ok) continue;
        cout << n << '\n';
        range(i, n) {
            range(j, n) {
                cout << result[i][j] << ' ';
            }
            cout << '\n';
        }
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}