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

struct ST_MIN {
	#define mid ((l + r) >> 1)
	#define ls p << 1
	#define rs p << 1 | 1 
	struct Node {ll v, l;} o[N << 2];
	void pu(int p) {o[p].v = max(o[ls].v, o[rs].v);}
	void ud(int p, ll v) {o[p].v += v, o[p].l += v;}
	void pd(int p) {if(o[p].l){ud(ls, o[p].l), ud(rs, o[p].l), o[p].l = 0;};}
	void Build(int p, int l, int r, int *F) {
		o[p].l = 0; if (l == r) return o[p].v = F[l], void();
		Build(ls, l, mid, F), Build(rs, mid + 1, r, F), pu(p); 
	}
	void Mdf(int p, int l, int r, int tl, int tr, ll v) {
		if (tr < l || r < tl || tl > tr) return; 
		if (tl <= l && r <= tr) return ud(p, v); pd(p);
		if (tl <= mid) Mdf(ls, l, mid, tl, tr, v);
		if (tr > mid) Mdf(rs, mid + 1, r, tl, tr, v);
		pu(p);
	}
	ll Qry(int p, int l, int r, int tl, int tr) {
		if (tr < l || r < tl || tl > tr) return -infll;
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
}	st;

int n, h[N], b[N], top;
ll dp[N];
int Min = inf, v = 0;
struct Node {
	int l, r, h, v;
}	sta[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(h[i]);
	for (int j = 1; j <= n; j++) read(b[j]);
	dp[1] = b[1], sta[++top] = (Node){1, 1, h[2], b[2]};
	st.Mdf(1, 1, n, 1, 1, dp[1] + b[2]);
	Min = h[1], v = b[1];
	for (int i = 2; i <= n; i++) {
		if (h[i] < Min) Min = h[i], v = b[i];
		dp[i] = max(st.Qry(1, 1, n, 1, i - 1), (ll)v);
		Node ne = (Node){i, i, h[i + 1], b[i + 1]}; st.Mdf(1, 1, n, i, i, dp[i]);
		while (top && sta[top].h > ne.h) {
			st.Mdf(1, 1, n, sta[top].l, sta[top].r, -sta[top].v);
			ne.l = sta[top].l, top--;
		}
		sta[++top] = ne;
		st.Mdf(1, 1, n, ne.l, i, ne.v);
	}
	print(dp[n], '\n');
	return 0;
}