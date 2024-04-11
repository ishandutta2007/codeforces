#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200002;
set<int> g[N];
ll s, ans = 0, w[N], dp[N];

void dfs(int v) {
    if (g[v].size() != 1 || v == s) {
        ans = max(ans, dp[v]);
        return;
    }
    int u = *g[v].begin();
    g[v].erase(u);
    g[u].erase(v);
    dp[u] = max(dp[u], dp[v] + w[v]);
    dfs(u);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, u, v;
    cin >> n >> m;
    rep(i, n)
        cin >> w[i];
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    cin >> s;
    s--;
    rep(i, n)
        dfs(i);
    rep(i, n)
        if (i == s || !g[i].empty())
            ans += w[i];
    cout << ans;
}