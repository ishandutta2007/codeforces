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

const int N = 3e5 + 10;

int first[N + 4 * N], cur;
struct Edge {
	int nxt, to, w, wh, lai;
}	e[N * 20];
void con(int x, int y, int z, int t) {
	e[++cur] = (Edge){first[x], y, z, t, x};
	first[x] = cur;
}

int n, a[N], b[N], c[N], cnt, rt[N << 2], dis[N * 5], from[N * 5];

void Build(int p, int l, int r) {
	if (l == r) {
		rt[p] = c[l];
		return;
	}
	rt[p] = ++cnt;
	int mid = (l + r) >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	if (rt[p << 1] <= n) con(rt[p], rt[p << 1], 0, l);
	else con(rt[p], rt[p << 1], 0, 0);
	if (rt[p << 1 | 1] <= n) con(rt[p], rt[p << 1 | 1], 0, r);
	else con(rt[p], rt[p << 1 | 1], 0, 0);
}

void Mdf(int p, int l, int r, int tl, int tr, int x) {
	if (tl <= l && r <= tr) {
		if (l == r) con(x, rt[p], 1, l);
		else con(x, rt[p], 1, 0);
		return;
	}
	int mid = (l + r) >> 1;
	if (tl <= mid) Mdf(p << 1, l, mid, tl, tr, x);
	if (tr > mid) Mdf(p << 1 | 1, mid + 1, r, tl, tr, x);
}

priority_queue <pii, vector<pii >, greater<pii > > q;
vector <int> ans;

int main() {
	memset(first, -1, sizeof first);
	memset(from, -1, sizeof from);
	read(n), cnt = n;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n; i++) c[i] = i + b[i];
	Build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		if (a[i] >= i) con(i, 0, 1, 0);
		Mdf(1, 1, n, max(1, i - a[i]), i, i);
	}
	memset(dis, 0x3f, sizeof dis), dis[n] = 0;
	q.push(mp(0, n));
	while (!q.empty()) {
		pii pr = q.top(); q.pop();
		int u = pr.se, s = pr.fi;
		if (dis[u] < s) continue;
		for (int i = first[u]; i != -1; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				from[v] = i;
				q.push(mp(dis[v], v));
			}
		}
	}
	if (dis[0] == 0x3f3f3f3f) {
		puts("-1");
		return 0;
	}
	print(dis[0], '\n');
	int tmp = 0; ans.push_back(tmp);
	while (tmp != n) {
		ans.push_back(e[from[tmp]].wh);
		tmp = e[from[tmp]].lai;
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		if (ans[i]) print(ans[i], ' ');
	print(0, '\n');
	return 0;
}