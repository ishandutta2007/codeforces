// Not my code
// https://codeforces.com/contest/848/submission/104365498

#pragma GCC optimize("O2,unroll-loops")//https://codeforces.com/contest/848/submission/90708221 but 64bit
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 100100, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, q, a[maxn];
struct isegtree {
	struct node {
		node *l, *r;
		ll sum;
		node(ll x = 0) : l(0), r(0), sum(x) {}
	};
	using pnode = node*;
	pnode root = 0;
	deque<node> buffer;
	pnode newnode() {
		buffer.emplace_back(0);
		return &buffer.back();
	}
	pnode add(int p, int v, pnode rt, int l, int r) {
		if(p < l || r < p) return rt;
		if(!rt) rt = newnode();
		rt->sum+=v;
		if(l != r) {
			int mid = (l+r)/2;
			rt->l = add(p, v, rt->l, l, mid);
			rt->r = add(p, v, rt->r, mid+1, r);
		}
		return rt;
	}
	void add(int p, int v) {
		root = add(p, v, root, 1, n);
	}
	ll get(int ql, int qr, int l, int r, pnode rt) {
		if(qr < l || r < ql || !rt) return 0;
		if(ql <= l && r <= qr) return rt->sum;
		int mid = (l+r)/2;
		return get(ql, qr, l, mid, rt->l) + get(ql, qr, mid+1, r, rt->r);
	}
	ll get(int ql, int qr) {
		return get(ql, qr, 1, n, root);
	}
};
isegtree tr[maxn];
void upd(int x, int y, int v) {
	for(;x <= n; x += x&-x) tr[x].add(y, v);
}
ll get(int x, int ly, int ry) {
	ll ans = 0;
	for(; x; x -= x&-x) ans += tr[x].get(ly, ry);
	return ans;
}
ll get(int lx, int rx, int ly, int ry) {
	return get(rx, ly, ry) - get(lx-1, ly, ry);
}
set<int> pos[maxn];
void insert(int p, int v) {
	auto l = pos[v].upper_bound(p);
	auto r = l;
	int f = 0;
	if(l != pos[v].begin())
		l--, upd(*l, p, p-*l), f += 1;
	if(r != pos[v].end())
		upd(p, *r, *r-p), f += 2;
	if(f == 3) upd(*l, *r, -(*r-*l));
	pos[v].insert(p);
}
void erase(int p, int v) {
	auto l = pos[v].lower_bound(p);
	auto r = l;
	int f = 0;
	if(l != pos[v].begin())
		l--, upd(*l, p, -(p-*l)), f += 1;
	if(++r != pos[v].end())
		upd(p, *r, -(*r-p)), f += 2;
	if(f == 3) {
		upd(*l, *r, (*r-*l));
	}
	pos[v].erase(p);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		insert(i, a[i]);
	}
	for(int t, l, r; q--;) {
		cin >> t >> l >> r;
		if(t == 2) cout << get(l, r, l, r) << '\n';
		else {
			erase(l, a[l]);
			insert(l, a[l] = r);
		}
	}
}