//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

const int maxn = (int) 1e5 + 42;

vector<int> graph[maxn];

void clear(int n) {
    for (int i = 1; i <= n; ++i) {
        graph[i].clear();
    }
}

void dfs(int v, int p, int dist, int &bestdist, int &bestv) {
    if (dist > bestdist) {
        bestdist = dist;
        bestv = v;
    }
    for (auto to: graph[v]) {
        if (to != p) {
            dfs(to, v, dist + 1, bestdist, bestv);
        }
    }
}

void dfs2(int v, int p, int dist, int fin, int &result) {
    if (v == fin) {
        result = dist;
    }
    for (auto to: graph[v]) {
        if (to != p) {
            dfs2(to, v, dist + 1, fin, result);
        }
    }
}

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int bestv = 1, bestdist = 0;
    dfs(1, -1, 0, bestdist, bestv);
    bestdist = 0;
    dfs(bestv, -1, 0, bestdist, bestv);
    
    int curdist = -1;
    dfs2(a, -1, 0, b, curdist);
    if (curdist <= da) {
        cout << "Alice\n";
    } else if (min(db, bestdist) >= 2 * da + 1) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
    clear(n);
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

	int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}