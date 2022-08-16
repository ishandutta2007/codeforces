#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

vi g[100001], grev[100001], scc[100001];
int n, m;

int cost[100001], f[100001];
int cur = 0;

bool visited[100001];
int s = 0;

void dfs(int x) {
    visited[x] = true;

    for (int &i : grev[x]) {
        if (!visited[i])
            dfs(i);
    }

    cur += 1;
    f[cur] = x;
}

void dfs2(int x) {
    visited[x] = true;
    scc[s].push_back(x);

    for (int &i : g[x]) {
        if (!visited[i])
            dfs2(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> cost[i];

    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        grev[v].push_back(u);
    }

    fill(visited, visited + n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }

    fill(visited, visited + n + 1, false);

    for (int i = n; i >= 1; i--) {
        if (!visited[f[i]]) {
            s = f[i];
            dfs2(f[i]);
        }
    }

    ll ans1 = 0, ans2 = 1;

    for (int i = 1; i <= n; i++) {
        if (!scc[i].empty()) {
            int c = 0, best = INT_MAX;

            for (int &x : scc[i]) {
                if (best > cost[x]) {
                    c = 1;
                    best = cost[x];
                }
                else if (best == cost[x])
                    c += 1;
            }

            ans2 = (ans2 * c) % mod;
            ans1 += best;
        }
    }

    cout << ans1 << " " << ans2 << "\n";
    return 0;
}