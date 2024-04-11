#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

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

struct ST_MIN {
	#define mid ((l + r) >> 1)
	#define ls p << 1
	#define rs p << 1 | 1 
	struct Node {int v, l;} o[N << 2];
	void pu(int p) {o[p].v = min(o[ls].v, o[rs].v);}
	void ud(int p, int v) {o[p].v += v, o[p].l += v;}
	void pd(int p) {if(o[p].l){ud(ls, o[p].l), ud(rs, o[p].l), o[p].l = 0;};}
	void Build(int p, int l, int r, int *F) {
		o[p].l = 0; if (l == r) return o[p].v = F[l], void();
		Build(ls, l, mid, F), Build(rs, mid + 1, r, F), pu(p); 
	}
	void Mdf(int p, int l, int r, int tl, int tr, int v) {
		if (tr < l || r < tl || tl > tr) return; 
		if (tl <= l && r <= tr) return ud(p, v); pd(p);
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
}	mn;

struct ST_MAX {
	#define mid ((l + r) >> 1)
	#define ls p << 1
	#define rs p << 1 | 1 
	struct Node {int v, l;} o[N << 2];
	void pu(int p) {o[p].v = max(o[ls].v, o[rs].v);}
	void ud(int p, int v) {o[p].v += v, o[p].l += v;}
	void pd(int p) {if(o[p].l){ud(ls, o[p].l), ud(rs, o[p].l), o[p].l = 0;};}
	void Build(int p, int l, int r, int *F) {
		o[p].l = 0; if (l == r) return o[p].v = F[l], void();
		Build(ls, l, mid, F), Build(rs, mid + 1, r, F), pu(p); 
	}
	void Mdf(int p, int l, int r, int tl, int tr, int v) {
		if (tr < l || r < tl || tl > tr) return; 
		if (tl <= l && r <= tr) return ud(p, v); pd(p);
		if (tl <= mid) Mdf(ls, l, mid, tl, tr, v);
		if (tr > mid) Mdf(rs, mid + 1, r, tl, tr, v);
		pu(p);
	}
	int Qry(int p, int l, int r, int tl, int tr) {
		if (tr < l || r < tl || tl > tr) return -inf;
		if (tl <= l && r <= tr) return o[p].v; pd(p);
		return max(Qry(ls, l, mid, tl, tr), Qry(rs, mid + 1, r, tl, tr));
	}
	void op(int p, int l, int r) {
		if (l == r) return print(o[p].v, ' '), void();
		op(ls, l, mid), op(rs, mid + 1, r);
	}
	void check(int n) {op(1, 1, n), puts("");}
	#undef mid
	#undef ls
	#undef rs
}	mx;

int T, n, a[N];

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		mn.Build(1, 1, n, a);
		mx.Build(1, 1, n, a);
		int x = 1, ans = 0;
		while (x != n) {
			if (a[x] < a[x + 1]) {
				int l = x + 1, r = n;
				if (mn.Qry(1, 1, n, l, r) < a[x]) {
					while (l < r) {
						int mid = (l + r) >> 1;
						if (mn.Qry(1, 1, n, x + 1, mid) < a[x]) r = mid;
						else l = mid + 1;
					}
					r--;
				}
				int t = mx.Qry(1, 1, n, x + 1, r);
				l = x + 1;
				while (l < r) {
					int mid = (l + r) >> 1;
					if (mx.Qry(1, 1, n, x + 1, mid) == t) r = mid;
					else l = mid + 1;
				}
				x = r;
			}
			else {
				int l = x + 1, r = n;
				if (mx.Qry(1, 1, n, l, r) > a[x]) {
					while (l < r) {
						int mid = (l + r) >> 1;
						if (mx.Qry(1, 1, n, x + 1, mid) > a[x]) r = mid;
						else l = mid + 1;
					}
					r--;
				}
				int t = mn.Qry(1, 1, n, x + 1, r);
				l = x + 1;
				while (l < r) {
					int mid = (l + r) >> 1;
					if (mn.Qry(1, 1, n, x + 1, mid) == t) r = mid;
					else l = mid + 1;
				}
				x = r;	
			}
			ans++;
		}
		print(ans, '\n');
	}
	return 0;
}