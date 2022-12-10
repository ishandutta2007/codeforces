//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5 + 10;
const LL Mod = 1000 * 1000 * 1000 + 7;
LL wei[maxn],
   pn[maxn],
   n, m;
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
    wei[u] = 1;
    for (auto v: adj[u])
        if (v != p) {
            dfs(v, u);
            wei[u] += wei[v];
        }
}

int solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        adj[i].clear();
    for (int i = 1; i < n; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        adj[se].PB(fi);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> pn[i];
    sort(pn, pn + m, greater<LL>());
    dfs(0);
    for (int i = 0; i < n; i++)
        wei[i] *= n - wei[i];
    sort(wei, wei + n, greater<LL>());
    for (int i = 0; i < n; i++)
        wei[i] %= Mod;
    LL ans = 0;
    if (m < n - 1) {
        for (int i = 0; i < m; i++)
            ans = (ans + wei[i] * pn[i]) % Mod;
        for (int i = m; i < n - 1; i++)
            ans = (ans + wei[i]) % Mod;
    }
    else {
        ans = wei[0];
        for (int i = 0; i <= m - (n - 1); i++)
            ans = (ans * pn[i]) % Mod;
        for (int i = 1; i < n - 1; i++)
            ans = (ans + wei[i] * pn[m - (n - 1) + i]) % Mod;
    }
    cout << ans << '\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}