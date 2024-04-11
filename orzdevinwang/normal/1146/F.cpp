#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int mod = 998244353;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
int n, fa[N], deg[N];
int head[N], edge_id;
struct edge {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, deg[u] ++, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
int f[N][3]; // 0 : ; 1 :  2 : 
void dfs(int x) {
	if(deg[x] == 0) {
		f[x][2] = 1;
		return;
	}
	f[x][0] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		dfs(v);
		int sav[3] = {f[x][0], f[x][1], f[x][2]};
		f[x][2] = ((ll) sav[2] * ((ll) f[v][0] + f[v][1] + f[v][2] * 2) % mod + (ll) sav[1] * (f[v][1] + f[v][2]) % mod) % mod;
		f[x][1] = ((ll) sav[1] * (f[v][0] + f[v][2]) % mod + (ll) sav[0] * (f[v][1] + f[v][2]) % mod) % mod;
		f[x][0] = (ll) sav[0] * (f[v][0] + f[v][2]) % mod;
		// cout << f[x][0] << " " << f[x][1] << " " << f[x][2] << endl;
	}
}
int main() {
	n = read();
	L(i, 2, n) fa[i] = read(), add_edge(fa[i], i);
	dfs(1);
	printf("%d\n", (f[1][0] + f[1][2]) % mod);
	return 0;
}