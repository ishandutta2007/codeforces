#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 4e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<gp_hash_table<int, int>> g(n);
    range(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    set<pair<int, int>> s;
    vector<int> deg(n);
    range(i, n) {
        deg[i] = g[i].size();
        s.insert({deg[i], i});
    }

    vector<int> alive(n, 1);
    while (!s.empty()) {
        auto[d, i] = *s.begin();
        if (d >= k) {
            int c = accumulate(all(alive), 0ll);
            cout << "1 " << c << "\n";
            range(i, n) {
                if (alive[i]) cout << i + 1 << " ";
            }
            cout << "\n";
            return;
        }
        if (d == k - 1) {
            vector<int> kek;
            for (auto &[u, p]: g[i]) {
                if (!alive[u]) continue;
                kek.push_back(u);
            }
            bool bad = false;
            for (auto &u: kek) {
                for (auto &u2: kek) {
                    if (u2 == u) break;
                    if (g[u].find(u2) == g[u].end()) {
                        bad = true;
                        break;
                    }
                }
                if (bad) break;
            }
            kek.push_back(i);
            if (!bad) {
                cout << "2\n";
                for (auto &x: kek) cout << x + 1 << " ";
                cout << "\n";
                return;
            }
        }
        s.erase(s.begin());
        alive[i] = 0;
        for (auto &[u, p]: g[i]) {
            if (!alive[u]) continue;
            s.erase({deg[u], u});
            deg[u]--;
            s.insert({deg[u], u});
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}