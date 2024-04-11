#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1 << 20;
const ll inf = 1e18;
int n, q, fa[N];
struct qwqwq {
	
ll a[N], b[N];
struct line {
	ll k, b;
	line (ll K = 0, ll B = 0) {
		k = K, b = B;
	}
};
pair < line, ll > Max (line a, line b) {
	if(a.b < b.b) swap(a, b);
	return make_pair (a, b.k > a.k ? (a.b - b.b) / (b.k - a.k) : inf);
}
ll tag[N], Ti[N];
line mx[N];
void upd (int x) {
	auto s = Max(mx[x << 1], mx[x << 1 | 1]); 
	Ti[x] = min(min(Ti[x << 1], Ti[x << 1 | 1]), s.second);
	mx[x] = s.first;
} 
void build (int x, int L, int R) {
	tag[x] = 0, Ti[x] = inf;
	if(L == R) return mx[x] = line (b[L], (ll) a[L] * b[L]), void ();
	int mid = (L + R) >> 1;
	build (x << 1, L, mid);
	build (x << 1 | 1, mid + 1, R);
	upd (x);
}
void push (int x) {
	mx[x << 1].b += mx[x << 1].k * tag[x];
	mx[x << 1 | 1].b += mx[x << 1 | 1].k * tag[x];
	Ti[x << 1] -= tag[x], Ti[x << 1 | 1] -= tag[x];
	tag[x << 1] += tag[x], tag[x << 1 | 1] += tag[x];
	tag[x] = 0;
}
void add (int x, int L, int R, int l, int r, int w) {
	int mid = (L + R) >> 1;
	if(l <= L && R <= r) {
		if(w > Ti[x]) {
			push (x);
			add (x << 1, L, mid, l, r, w);
			add (x << 1 | 1, mid + 1, R, l, r, w);
			upd (x);
		} else Ti[x] -= w, tag[x] += w, mx[x].b += mx[x].k * w;
		return ;
	}
	push (x);
	if(l <= mid) add (x << 1, L, mid, l, r, w);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, w);
	upd (x);
}
ll query (int x, int L, int R, int l, int r) { 
	if(l <= L && R <= r) return mx[x].b;
	push (x);
	int mid = (L + R) >> 1;
	ll ret = -1e18;
	if(l <= mid) ret = max(ret, query(x << 1, L, mid, l, r));
	if(r > mid) ret = max(ret, query(x << 1 | 1, mid + 1, R, l, r));
	return ret; 
}

} A, B;
ll a[N], w[N];
int ehd[N], enx[N], dfn[N], en[N], idt;
void dfs (int x) {
	dfn[x] = ++idt;
	for (int v = ehd[x]; v; v = enx[v]) dfs(v);
	en[x] = idt;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 2, n) cin >> fa[i];
	L(i, 1, n) cin >> a[i], a[i] += a[fa[i]];
	L(i, 1, n) cin >> w[i], w[i] += w[fa[i]];
	L(i, 2, n) enx[i] = ehd[fa[i]], ehd[fa[i]] = i;	 
	dfs (1);
	L(i, 1, n) A.b[dfn[i]] = w[i], B.b[dfn[i]] = -w[i], A.a[dfn[i]] = B.a[dfn[i]] = a[i];
	A.build(1, 1, n), B.build(1, 1, n);
	while (q--) {
		int op, x, w;
		cin >> op >> x ;
		if(op == 1) {
			cin >> w; 
			A.add(1, 1, n, dfn[x], en[x], w);
			B.add(1, 1, n, dfn[x], en[x], w);
		} else {
			cout << max(A.query(1, 1, n, dfn[x], en[x]), B.query(1, 1, n, dfn[x], en[x])) << '\n';
		}
	}
	return 0;
}