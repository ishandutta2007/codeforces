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
inline void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
inline void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

struct ST_MIN {
	#define mid ((l + r) >> 1)
	#define ls p << 1
	#define rs p << 1 | 1 
	struct Node {int v, l;} o[N << 2];
	void pu(int p) {o[p].v = min(o[ls].v, o[rs].v);}
	void ud(int p, int v) {o[p].v += v, o[p].l += v;}
	void pd(int p) {if(o[p].l){ud(ls, o[p].l), ud(rs, o[p].l), o[p].l = 0;};}
	void Build(int p, int l, int r) {
		o[p].l = 0; if (l == r) return o[p].v = inf, void();
		Build(ls, l, mid), Build(rs, mid + 1, r), pu(p); 
	}
	void Mdf(int p, int l, int r, int tl, int tr, int v) {
		if (tr < l || r < tl || tl > tr) return; 
		if (tl <= l && r <= tr) return o[p].v = min(o[p].v, v), void(); pd(p);
		if (tl <= mid) Mdf(ls, l, mid, tl, tr, v);
		if (tr > mid) Mdf(rs, mid + 1, r, tl, tr, v);
		pu(p);
	}
	int Qry(int p, int l, int r, int tl, int tr) {
		if (tr < l || r < tl || tl > tr) return inf;
		if (tl <= l && r <= tr) return o[p].v; pd(p);
		return min(Qry(ls, l, mid, tl, tr), Qry(rs, mid + 1, r, tl, tr));
	}
	void op(int p, int l, int r) {
		if (l == r) return print(o[p].v, ' '), void();
		op(ls, l, mid), op(rs, mid + 1, r);
	}
	void check(int n) {op(1, 1, n), puts("");}
	#undef mid
	#undef ls
	#undef rs
}	st;

int n, q, fa[N], siz[N], f[N];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void con(int x, int y) {if (find(x) != find(y)) siz[fa[y]] += siz[fa[x]], fa[fa[x]] = fa[y];}

int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	st.Build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int t, l, r, x;
		read(t);
		if (t == 0) {
			read(l), read(r), read(x);
			if (x == 0) {
				int st1 = find(l);
				while (st1 <= r) {
					f[st1] = 1;
					if (st1 > 1 && f[st1 - 1]) con(st1 - 1, st1);
					if (st1 < n && f[st1 + 1]) con(st1, st1 + 1);
					st1 = find(st1) + 1;
				}
			}
			else
				st.Mdf(1, 1, n, l, l, r);
		}
		else {
			read(x);
			if (f[x]) puts("NO");
			else {
				l = r = x;
				if (f[x - 1]) l = x - siz[x - 1];
				if (f[x + 1]) r = find(x + 1);
				if (st.Qry(1, 1, n, l, r) <= r) puts("YES");
				else puts("N/A");
			}
		}
	}
	return 0;
}