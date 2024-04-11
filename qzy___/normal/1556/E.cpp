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

struct Node {
	ll mx, mn; ll s;
};

Node merge(Node A, Node B) {
	Node ret = (Node){0, 0, 0};
	ret.s = A.s + B.s;
	ret.mx = max(A.mx, A.s + B.mx);
	ret.mn = min(A.mn, A.s + B.mn);
	return ret;
}
const int N = 1e5 + 10;

Node o[N << 2];

int n, q; ll a[N], b[N];

void Build(int p, int l, int r) {
	if (l == r) {
		o[p] = (Node){b[l] - a[l], b[l] - a[l], b[l] - a[l]};
		return;
	}
	int mid = (l + r) >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	o[p] = merge(o[p << 1], o[p << 1 | 1]);
	//cout << l << " " << r << " " << o[p].a << " " << o[p].x << " " << o[p].y << endl;
}

Node Qry(int p, int l, int r, int tl, int tr) {
	if (tr == 0) return (Node){0, 0, 0};
	if (tl <= l && r <= tr) return o[p];
	int mid = (l + r) >> 1;
	if (tr <= mid) return Qry(p << 1, l, mid, tl, tr);
	if (tl > mid) return Qry(p << 1 | 1, mid + 1, r, tl, tr);
	return merge(Qry(p << 1, l, mid, tl, tr), Qry(p << 1 | 1, mid + 1, r, tl, tr));
}

int main() {
	scanf("%d%d", &n, &q);
	lep (i, 1, n) read(a[i]);
	lep (i, 1, n) read(b[i]);
	Build(1, 1, n);
	lep (i, 1, q) {
		int l, r; read(l), read(r);
		Node t = Qry(1, 1, n, l, r);
		if (t.s != 0 || t.mn < 0) puts("-1");
		else print(t.mx, '\n');
	}
	return 0;
}