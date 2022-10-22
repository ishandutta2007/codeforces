#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
const ll P = 1e9 + 7;
int n, f[N];
ll sz[N], dp[N];
vector <int> G[N];
void dfs(int u, int fa) {
	for(int v : G[u]) if(v ^ fa) dfs(v, u), sz[u] += sz[v];
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll calc(int u) {
	if(f[u] ^ u) return 0;
	if(dp[u]) return dp[u];
	per(i, n / u, 2) dp[u] += calc(u * i);
	return ++dp[u] %= P;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%lld", &sz[i]);
	int p;
	rep(i, 2, n) {
		scanf("%d", &p);
		G[p].push_back(i), G[i].push_back(p);
	}
	dfs(1, 0);
	rep(i, 1, n) {
		ll t = sz[1] / gcd(sz[1], sz[i]);
		if(t <= n) f[t]++;
	}
	per(i, n, 1) if(f[i]) per(j, n / i, 2) f[i * j] += f[i];
	cout << calc(1);
	return 0;
}