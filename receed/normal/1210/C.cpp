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

const int N = 100002, L = 18, MOD = 1e9 + 7;
ll up[L][N], ux[L][N], h[N];
vector<int> g[N];

void dfs(int v, int p) {
    up[0][v] = p;
    for (int u : g[v])
        if (u != p) {
            h[u] = h[v] + 1;
            up[0][u] = v;
            dfs(u, v);
        }
}
int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, u, v;
    cin >> n;
    rep(i, n)
        cin >> ux[0][i];
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    up[0][0] = -1;
    rep(i, L - 1)
        rep(j, n) {
            up[i + 1][j] = (up[i][j] == -1 ? -1 : up[i][up[i][j]]);
            ux[i + 1][j] = __gcd(ux[i][j], ux[i][up[i][j]]);
        }
    ll ans = 0;
    rep(i, n) {
        ll cg = ux[0][i], cv = i;
        while (cv > 0) {
            int lv = cv;
            for (int j = L - 1; j >= 0; j--) {
                if (up[j][cv] != -1 && (cg == 0 && ux[j][cv] == 0 || cg > 0 && ux[j][cv] % cg == 0))
                    cv = up[j][cv];
            }
            ans = (ans + cg % MOD * (h[lv] - h[cv]) % MOD) % MOD;
            cg = __gcd(cg, ux[0][cv]);
        }
        ans = (ans + cg) % MOD;
    }
    cout << ans % MOD;
}