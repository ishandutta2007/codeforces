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

const int maxn = 3e5 + 10;
const LL Mod = 998244353;
vector<int> adj[maxn];
LL dp[maxn],
   pd[maxn],
   alone[maxn];
int n;

void dfs(int u, int p = -1) {
	dp[u] = pd[u] = 0;
	alone[u] = 1;
	for (auto v : adj[u])
		if (v ^ p) {
			dfs(v, u);
			dp[u] = ((dp[u] * (2 * dp[v] + alone[v]) % Mod) + ((alone[u] + pd[u]) * (alone[v] + pd[v]) % Mod)) % Mod;
			pd[u] = (pd[u] * (dp[v] * 2 + alone[v]) + alone[u] * dp[v]) % Mod;
			alone[u] = (alone[u] * (alone[v] + dp[v])) % Mod;
			//cout << u << ' ' << v << ' ' << alone[u] << ' ' << pd[u] << ' ' << dp[u] << endl;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	cout << (dp[0] + alone[0]) % Mod << endl;
	return 0;
}