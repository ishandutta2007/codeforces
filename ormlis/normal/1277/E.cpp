#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;

int n, m;
vector<int> g1[200001];
int used[200001];
int f = 0, a, b;
int tin[200001];
int up[200001];
int t = 1;
int flag = 0;

void dfs1(int v, int p) {
    used[v] = 1;
    tin[v] = up[v] = t++;
    int child = 0;
    for (auto u: g1[v]) {
        if (p == u) continue;
        if (!used[u]) {
            dfs1(u, v);
            child++;
            up[v] = min(up[v], up[u]);
            if (tin[v] <= up[u] && p != -1) {
                if (v == a && f < 10) {
                    f += 10;
                }
                if (v == b && f % 10 == 0) {
                    f += 1;
                }
            }
        } else {
            up[v] = min(up[v], tin[u]);
        }
    }
    if (p == -1 && child > 1) {
        if (v == a && f < 10) {
            f += 10;
        }
        if (v == b && f % 10 == 0) {
            f += 1;
        }
    }
}

int dfs2(int v, int c1) {
    used[v] = 1;
    int c = 1;
    for (auto u: g1[v]) {
        if (!used[u] && u != c1) {
            c += dfs2(u, c1);
        }
    }
    return c;
}


void solve() {
    t = 1;
    int u, v;
    cin >> n >> m >> a >> b;
    range(i, n + 1) {
        g1[i].clear();
        used[i] = tin[i] = up[i] = 0;
    }
    range(i, m) {
        cin >> u >> v;
        g1[u].emplace_back(v);
        g1[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            dfs1(i, -1);
        }
    }
    if (f < 10 || f % 10 == 0) {
        cout << 0 << '\n';
        return;
    }
    range(i, n + 1) {
        used[i] = 0;
    }
    ll ans = n - 1 - dfs2(b, a);
    range(i, n + 1) {
        used[i] = 0;
    }
    ans *= n - 1 - dfs2(a, b);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int te;
    cin >> te;
    range(i, te) {
        solve();
    }
    return 0;
}