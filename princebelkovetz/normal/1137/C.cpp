#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#pragma GCC optimize("O3")
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define ll long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e5 + 2, D = 51;

int n, m, d;
vector <int> g[N], rev[N];
int col[N][D], dp[N * D];
ll used[N];
string a[N];
vector <pair <int, int>> ts;
bool have[N];

void dfs(int v, int t) {
    used[v] ^= 1ll << t;
    int t1 = (t + 1) % d;
    for (auto& u : g[v]) {
        if ((used[u] >> t1) & 1 ^ 1) dfs(u, t1);
    }
    ts.push_back({ v, t });
}
void paint(int v, int t, int c, vector <pair <int, int>>& vs) {
    col[v][t] = c;
    vs.push_back({ v, t });
    int t1 = (t - 1 + d) % d;
    for (auto& u : rev[v]) {
        if (col[u][t1] == -1)
            paint(u, t1, c, vs);
        else
            dp[c] = max(dp[c], dp[col[u][t1]]);
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    cin >> n >> m >> d;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        rev[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < d; ++j) {
            if ((used[i] >> j) & 1 ^ 1) dfs(i, j);
            col[i][j] = -1;
        }
        g[i].shrink_to_fit();
    }
    reverse(ts.begin(), ts.end());

    int curColor = 0, ans = 0;
    vector <pair <int, int>> vs;
    for (auto& x : ts) {
        int i = x.first, j = x.second;
        if (col[i][j] == -1) {
            dp[curColor] = -mod;
            paint(i, j, curColor++, vs);
            if (col[1][0] == curColor - 1) dp[curColor - 1] = 0;
            for (auto& x : vs) {
                if (a[x.first][x.second] == '1' and !have[x.first])
                    dp[curColor - 1]++, have[x.first] = true;
            }
            for (auto& x : vs)
                have[x.first] = false;
            vs.clear();
            vs.shrink_to_fit();
            ans = max(ans, dp[curColor - 1]);
        }
    }
    cout << ans << '\n';

    return 0;
}