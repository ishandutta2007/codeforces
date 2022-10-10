#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 1007;
const int MM = 15;
const int INF = 1000 * 1000 * 1000 + 7;

char f[MX][MM][MM];
vector<pair<int, int> > g[MX];
int w[MX][MX];
int d[MX];
int od[MX];
bool was[MX];

void dfs(int v, int p) {
    for (const auto& e : g[v]) {
        int to = e.first, tot = e.second;
        if (to == p) {
            continue;
        }
        if (tot == 0) {
            cout << to << " 0\n";
        } else {
            cout << to << " " << v << "\n";
        }
        dfs(to, v);
    }
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    int n, m, k, ww;
    cin >> n >> m >> k >> ww;
    for (int i = 1; i <= k; i++) {
        for (int x = 0; x < n; x++) {
            string s;
            cin >> s;
            for (int y = 0; y < m; y++) {
                f[i][x][y] = s[y];
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            int cw = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    cw += (f[i][x][y] != f[j][x][y]);
                }
            }
            w[i][j] = min(n * m, cw * ww);
        }
    }

    auto ad = [&](int u, int v) {
        if (w[u][v] == n * m) {
            g[u].emplace_back(v, 0);
            g[v].emplace_back(u, 0);
        } else {
            g[u].emplace_back(v, 1);
            g[v].emplace_back(u, 1);
        }
    };

    for (int i = 1; i <= k; i++) {
        d[i] = INF;
        od[i] = -1;
    }
    d[1] = 0;
    ll res = 0;
    for (int i = 1; i <= k; i++) {
        int v = -1;
        for (int j = 1; j <= k; j++) {
            if (!was[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        assert(v != -1);
        if (v != 1) {
            ad(od[v], v);
        }
        was[v] = true;
        res += d[v];
        for (int u = 1; u <= k; u++) {
            if (w[v][u] < d[u]) {
                d[u] = w[v][u];
                od[u] = v;
            }
        }
    }

    cout << res + n * m << "\n";
    cout << "1 0\n";
    dfs(1, 1);

    return 0;
}