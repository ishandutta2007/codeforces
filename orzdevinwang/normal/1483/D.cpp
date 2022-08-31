#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 666, M = N * N;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
using namespace std;
ll f[N][N], g[N][N], s[N][N];
int n, m, q, u[M], v[M], w[M], ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	memset(g, - 0x3f, sizeof(g));
	L(i, 1, n) f[i][i] = 0;
	L(i, 1, m) {
		cin >> u[i] >> v[i] >> w[i]; 
		f[u[i]][v[i]] = min(f[u[i]][v[i]], (ll) w[i]);
		f[v[i]][u[i]] = min(f[v[i]][u[i]], (ll) w[i]);
	}
	L(k, 1, n) L(i, 1, n) L(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	cin >> q;
	L(i, 1, q) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = max(g[u][v], (ll) w);
		g[v][u] = max(g[v][u], (ll) w);
	}
	L(i, 1, n) L(j, 1, n) L(k, 1, n) s[i][j] = min(s[i][j], - g[i][k] + f[k][j]);
	L(i, 1, m) {
		ll mn = 1e16;
		L(j, 1, n) mn = min(mn, f[u[i]][j] + s[j][v[i]]);
		L(j, 1, n) mn = min(mn, f[v[i]][j] + s[j][u[i]]);
		mn += w[i];
		if(mn <= 0) ans ++;
	} 
	cout << ans << "\n";
	return 0;
}