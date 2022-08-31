#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2.5e3+10, MOD = 1e9+7;
const int INF = 1e9+10;

int n, a[MAXN][MAXN];

vector<ar<int, 2>> adj[MAXN];
ar<int, 2> min_e[MAXN];
bool vis[MAXN];

void get_mst() {
    for (int i = 0; i < n; i++) min_e[i] = {INF, -1};
    min_e[0][0] = 0;

    auto add_edge = [&](int a, int b, int w) {
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    };

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) if (!vis[j] && (v == -1 || min_e[j][0] < min_e[v][0])) 
            v = j;
        if (min_e[v][0] == INF) assert(false);

        vis[v] = 1;

        if (min_e[v][1] != -1)
            add_edge(v, min_e[v][1], min_e[v][0]);

        for (int to = 0; to < n; to++) {
            if (a[v][to] < min_e[to][0])
                min_e[to] = {a[v][to], v};
        }
    }
}
void dfs(int c, int p, int x, int root) {
    if (a[c][root] != x) {
        cout << "NOT MAGIC\n";
        exit(0);
    }
    for (auto [nxt, w] : adj[c]) if (nxt != p) {
        dfs(nxt, c, max(w, x), root);
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    get_mst();
    for (int i = 0; i < n; i++) {
        dfs(i, -1, 0, i);
    }
    cout << "MAGIC\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}