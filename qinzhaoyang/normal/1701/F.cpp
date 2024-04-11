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

const int N = 2e5 + 10;

struct Node {
	ll s2, s1, s0, lz;
}	o[N << 2];

void pu(int x) {
	o[x].s0 = o[x << 1].s0 + o[x << 1 | 1].s0;
	o[x].s1 = o[x << 1].s1 + o[x << 1 | 1].s1;
	o[x].s2 = o[x << 1].s2 + o[x << 1 | 1].s2;
}

void ud(int x, ll v) {
	o[x].s2 += 2 * v * o[x].s1 + v * v * o[x].s0;
	o[x].s1 += v * o[x].s0;
	o[x].lz += v;
}

void pd(int x) {
	if (o[x].lz) {
		ud(x << 1, o[x].lz);
		ud(x << 1 | 1, o[x].lz);
		o[x].lz = 0;
	}
}

void Mdf(int x, int l, int r, int tl, int tr, int v) {
	if (tl > tr) return;
	if (tl <= l && r <= tr) return ud(x, v);
	int mid = (l + r) >> 1; pd(x);
	if (tl <= mid) Mdf(x << 1, l, mid, tl, tr, v);
	if (tr > mid) Mdf(x << 1 | 1, mid + 1, r, tl, tr, v);
	pu(x);
}

int val = 0;
int Qry(int x, int l, int r, int p) {
	if (l == r) {
		int ret = o[x].s0;
		o[x].s0 = 1 - o[x].s0;
		if (o[x].s0 == 0) o[x].s1 = o[x].s2 = 0;
		else o[x].s1 = val, o[x].s2 = 1ll * val * val;
		return ret;
	}
	pd(x);
	int mid = (l + r) >> 1, ret = 0;
	if (p <= mid) ret = Qry(x << 1, l, mid, p);
	else ret = Qry(x << 1 | 1, mid + 1, r, p);
	pu(x);
	return ret;
}

int ask(int x, int l, int r, int tl, int tr) {
	if (tl > tr) return 0;
	if (tl <= l && r <= tr) return o[x].s0;
	pd(x); int mid = (l + r) >> 1, ret = 0;
	if (tl <= mid) ret += ask(x << 1, l, mid, tl, tr);
	if (tr > mid) ret += ask(x << 1 | 1, mid + 1, r, tl, tr);
	return ret;
}

int q, d;

int main() {
	scanf("%d%d", &q, &d);
	for (int i = 1; i <= q; i++) {
		int x; scanf("%d", &x);
		val = ask(1, 1, 200000, max(1, x - d), x - 1);
		int r = Qry(1, 1, 200000, x);
		Mdf(1, 1, 200000, x + 1, min(200000, x + d), r ? -1 : 1);
		printf("%lld\n", (o[1].s2 - o[1].s1) / 2);
	}
	return 0;
}