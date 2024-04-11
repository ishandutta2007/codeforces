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
const int N = 2e5 + 5;

int n, dp[N], red[N], c = 0, d[N];
vi g[N], grev[N];

bool visited[N];

void dfs(int x, int p = 0, int depth = 0, int t = 0) {
    d[x] = depth;

    red[x] = red[p];
    if (t == 1)
        red[x] += 1;

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x, depth + 1, 0);
    }

    for (int &i : grev[x]) {
        if (i == p) continue;
        dfs(i, x, depth + 1, 1);
        c += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        grev[v].push_back(u);
    }

    dfs(1);

    int best_val = INT_MAX;
    for (int i = 1; i <= n; i++) {
        best_val = min(best_val, c - 2 * red[i] + d[i]);
//        cout << red[i] << " ";
    }

    cout << best_val << "\n";
    for (int i = 1; i <= n; i++) {
        if (c - 2 * red[i] + d[i] == best_val)
            cout << i << " ";
    }
    return 0;
}