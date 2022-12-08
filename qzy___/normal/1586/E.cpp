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
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

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

const int N = 3e5 + 10;

int first[N], cur;
struct Edge {
	int nxt, to;
}	e[N << 1];
void con(int x, int y) {
	if (x == 0 || y == 0) return;
	e[++cur] = (Edge){first[x], y};
	first[x] = cur;
}

int n, m, q, vis[N], fa[N], dep[N];
vector <int> G[N];

void build(int x, int Fa) {
	fa[x] = Fa, vis[x] = 1, dep[x] = dep[Fa] + 1;
	con(Fa, x);
	for (int v : G[x]) {
		if (v == Fa) continue;
		if (vis[v]) continue;
		build(v, x);
	}
}

int a[N], b[N], l[N], c[N];

int Lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	while (dep[x] > dep[y]) x = fa[x];
	while (x != y) x = fa[x], y = fa[y];
	return x;
}

int ans = 0, f[N];

void dfs(int x) {
	int cnt = 0;
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to; if (v == fa[x]) continue;
		dfs(v), c[x] += c[v];
		if (f[v]) cnt++;
	}
	if (x != 1) f[x] = (c[x] & 1);
	if (!f[x]) ans += (cnt + 1) / 2;
	else ans += cnt / 2;
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x), read(y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	build(1, 0); read(q);
	for (int i = 1; i <= q; i++) {
		read(a[i]), read(b[i]);
		l[i] = Lca(a[i], b[i]);
		c[a[i]]++, c[b[i]]++, c[l[i]] -= 2;
	}
	dfs(1);
	if (!ans) {
		puts("YES");
		for (int i = 1; i <= q; i++) {
			vector <int> v1;
			while (a[i] != l[i]) v1.push_back(a[i]), a[i] = fa[a[i]];
			vector <int> v2;
			while (b[i] != l[i]) v2.push_back(b[i]), b[i] = fa[b[i]];
			v1.push_back(l[i]);
			while (v2.size()) v1.push_back(v2.back()), v2.pop_back();
			print((int)v1.size(), '\n');
			for (int i = 0; i < v1.size(); i++)
				print(v1[i], ' '); puts("");
		}
	}
	else puts("NO"), print(ans, '\n');
	return 0;
}