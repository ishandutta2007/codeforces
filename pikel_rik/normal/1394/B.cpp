#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m, k, in[N][10][10], cur[10], ans;
vector<pair<int, int>> g[N], grev[N];

bool bad1[10][10], bad2[10][10][10][10];

void recurse(int num) {
    if (num == k + 1) {
        bool ok = true;
        for (int i = 1; i <= k; i++) {
            ok &= !bad1[i][cur[i]];
            for (int j = 1; j < i; j++) {
                ok &= (!bad2[i][cur[i]][j][cur[j]]);
            }
        }
//        for (int i = 1; i <= k; i++) cout << cur[i] << " "; cout << ok << "\n";
        ans += ok;
        return;
    }
    for (int i = 1; i <= num; i++) {
        cur[num] = i;
        recurse(num + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(w, v);
        grev[v].emplace_back(w, u);
    }

    for (int i = 1; i <= n; i++) {
        sort(all(g[i]));
    }

    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < g[u].size(); i++) {
            in[g[u][i].second][g[u].size()][i + 1]++;
        }
    }

    for (int u = 1; u <= n; u++) {
        vector<pair<int, int>> v1;
        for (auto &[w, v] : grev[u]) {
            for (int i = 0; i < g[v].size(); i++) {
                if (g[v][i].second != u) continue;

                if (in[u][g[v].size()][i + 1] != 1) {
                    bad1[g[v].size()][i + 1] = true;
                }
                else {
                    for (auto &[x, y] : v1) {
                        bad2[g[v].size()][i + 1][x][y] = bad2[x][y][g[v].size()][i + 1] = true;
                    }
                    v1.emplace_back(g[v].size(), i + 1);
                }
            }
        }
    }

    recurse(1);
    cout << ans << "\n";
    return 0;
}