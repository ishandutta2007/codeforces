#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 111;
const int mod = 1e9 + 7;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
int qpow(int x, int y = mod - 2, int p = mod) {
	int res = 1;
	for(; y; x = (ll) x * x % p, y >>= 1) if(y & 1) res = (ll) res * x % p;
	return res;
}
int n, siz[N], dp[N][N][2]; 
int fac[N], ifac[N];
void math_init(int x) {
	fac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[x] = qpow(fac[x]);
	R(i, x, 1) ifac[i - 1] = (ll) ifac[i] * i % mod;
}
int C(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int sav[N][2];
int head[N], edge_id;
struct edge {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs(int x, int fa) {
	dp[x][0][1] = dp[x][0][0] = 1;
	siz[x] = 1;
	for(int t = head[x]; t; t = e[t].next) {
		int v = e[t].to;
		if(v == fa) continue;
		dfs(v, x);
		L(i, 0, siz[x] + siz[v]) sav[i][0] = sav[i][1] = 0;
		L(i, 0, siz[x]) L(j, 0, siz[v]) {
			(sav[i + j][0] += (ll) dp[x][i][0] * dp[v][j][0] % mod) %= mod;
			(sav[i + j][1] += (ll) dp[x][i][1] * dp[v][j][0] % mod) %= mod;
			(sav[i + j][1] += (ll) dp[x][i][0] * dp[v][j][1] % mod) %= mod;
		}
		siz[x] += siz[v];
		L(i, 0, siz[x]) dp[x][i][0] = sav[i][0], dp[x][i][1] = sav[i][1];
	}
	L(i, 0, siz[x]) (dp[x][i + 1][0] += dp[x][i][1]) %= mod;
}
int f[N], g[N];
int fpow(int x) {
	return x % 2 == 0 ? 1 : mod - 1;
}
int main() {
	n = read();
	math_init(n);
	L(i, 1, n - 1) {
		int u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
	}
	dfs(1, -1);
	L(i, 1, n) f[i] = dp[1][i - 1][1];
	f[1] = 1;
	L(i, 2, n) f[i] = (ll) f[i] * qpow(n, i - 2) % mod;
	reverse(f, f + n + 1);
	L(i, 0, n - 1) L(j, i, n - 1) (g[i] += (ll) C(j, i) * f[j] % mod * fpow(j - i) % mod) %= mod;
	L(i, 0, n - 1) printf("%d ", g[i]);
	puts("");
	return 0;
}