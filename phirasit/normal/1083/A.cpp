#include <iostream>
#include <vector>

using namespace std;

const int N = 3e5 + 10;

using pii = pair<int, int>;

vector<pii> adj[N];
long long w[N];
int n;

long long ans = 0;

long long dfs(int u, int p) {
    long long best1 = 0;
    for (pii e : adj[u]) {
        long long v = e.first, c = e.second;
        if (v == p) continue;
        long long val = dfs(v, u) - c;
        ans = max(ans, best1 + val + w[u]);
        best1 = max(best1, val);
    }

    ans = max(ans, best1 + w[u]);
    return best1 + w[u];
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 0; i < n-1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}