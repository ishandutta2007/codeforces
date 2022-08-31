#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7, inv2 = (mod + 1) / 2;
int n, ns, dp[N][N], inv[N];
vi e[N];
int rt, f[N], dep[N], siz[N];
void dfs1(int x, int fa) {
	siz[x] = 1;
	for(const int &v : e[x]) if(v != fa) dep[v] = dep[x] + 1, dfs1(v, x), siz[x] += siz[v];
}
void dfs2(int x, int fa) {
	f[dep[x]] = siz[x];
	if(x < rt) {
		L(i, 1, dep[x] - 1) (ns += (ll) dp[dep[x]][i] * (f[i] - f[i + 1]) % mod) %= mod;
	} 
	for(const int &v : e[x]) if(v != fa) dfs2(v, x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, inv[1] = 1;
	L(i, 2, n) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	}
	L(i, 2, n) {
		dp[i][1] = 1, dp[i][i] = 0;
		L(j, 2, i - 1) dp[i][j] = (ll) inv2 * (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
	}
	L(i, 1, n) rt = i, dep[i] = 1, dfs1(i, 0), dfs2(i, 0);
	cout << (ll) ns * inv[n] % mod << "\n";
	return 0;
}