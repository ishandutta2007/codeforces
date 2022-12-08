#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 610;

int n, m, q, Ans;
ll d[N][N];
int e1[N * N], e2[N * N], e3[N * N];
vector <pii > G[N];
ll f[N][N];

int check(int u, int v, int l) {
	for (int a = 1; a <= n; a++)
		if (f[a][v] >= d[a][u] + l)
			return true;
	return false;
}

int main() {
	read(n), read(m), mset(d, 0x3f);
	for (int i = 1; i <= n; i++)
		d[i][i] = 0; 
	for (int i = 1; i <= m; i++) {
		int x, y, v; read(x), read(y), read(v);
		e1[i] = x, e2[i] = y, e3[i] = v;
		d[x][y] = d[y][x] = v;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
	read(q);
	for (int i = 1; i <= q; i++) {
		int u, v, l; read(u), read(v), read(l);
		G[u].pb(mp(v, l)), G[v].pb(mp(u, l)); 
	}
	for (int a = 1; a <= n; a++)
		for (int c = 1; c <= n; c++)
			for (pii k : G[a])
				ckmax(f[a][c], k.se - d[k.fi][c]); 
	for (int e = 1; e <= m; e++) {
		if (check(e1[e], e2[e], e3[e]) || check(e2[e], e1[e], e3[e]))
			Ans++;
	}
	print(Ans, '\n');
	return 0;
}