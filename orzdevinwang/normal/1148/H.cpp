#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7, M = N * 60;
int n, m, mexl[N], mexr[N], las[N];
ll lns;
namespace seg1 {
	int h[N << 2], mn[N << 2];
	void upd (int x) {
		mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	}
	void add (int x, int L, int R, int p, int w) {
		if (L == R) return mn[x] = w, void ();
		int mid = (L + R) >> 1;
		if(p <= mid) add (x << 1, L, mid, p, w);
		else add (x << 1 | 1, mid + 1, R, p, w);
		upd (x);
	}
	int query (int x, int L, int R, int l, int w) { // [l,n]  <= w  
		if(mn[x] > w) return 0;
		if(L == R) return L;
		int mid = (L + R) >> 1, t;
		if(l <= mid && (t = query (x << 1, L, mid, l, w))) return t;
		return query (x << 1 | 1, mid + 1, R, l, w);
	}
}

struct node {
	int L, R, mid, tag;
	ll sum;
	node * ls, * rs;
	node (int _L, int _R) { 
		L = _L, R = _R, mid = (L + R) >> 1, tag = sum = 0, ls = rs = NULL;
	}
	void build () {
		if(L == R) return ;
		int mid = (L + R) >> 1; 
		ls = new node (L, mid);
		rs = new node (mid + 1, R);
		ls -> build ();
		rs -> build ();
	}
	void Add (int w) {
		sum += (ll) (R - L + 1) * w, tag += w;
	}
	void pushdown () {
		if(tag) 
			ls = new node (* ls), rs = new node (* rs), 
			ls -> Add (tag), rs -> Add (tag), tag = 0;
	}
	void upd () {
		sum = ls -> sum + rs -> sum;
	}
	void add (node * a, int l, int r, int w) {
		if(l <= L && R <= r) return Add (w);
		ls = new node (* (a -> ls)), rs = new node (* (a -> rs));
		pushdown ();
		if(l <= mid) ls -> add (a -> ls, l, r, w);
		if(r > mid) rs -> add (a -> rs, l, r, w);
		upd ();
	}
	ll query (int l, int r) {
		if(l <= L && R <= r) return sum;
		int mid = (L + R) >> 1;
		pushdown ();
		ll ret = 0;
		if(l <= mid && ls != NULL) ret += ls -> query (l, r);
		if(r > mid && rs != NULL) ret += rs -> query (l, r);
		return ret;
	}
} ; 
node * nul;
vi ti[N], hl[N], hr[N];
vector < node * > vc[N];
void Add (int x, int t) { 
	if(ti[x].back() != t) {
		node *u = vc[x].back();
		vc[x].push_back(new node (* u));
		if(hl[x].back()) vc[x].back() -> add (u, hl[x].back(), hr[x].back(), t - ti[x].back());
		ti[x].push_back(t), hl[x].push_back(mexl[x]), hr[x].push_back(mexr[x]); 
	}
	else hl[x].back () = mexl[x], hr[x].back () = mexr[x]; 
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	nul = new node (0, n), nul -> build ();
	L(x, 0, n) hl[x].push_back(0), hr[x].push_back(0), ti[x].push_back(0), vc[x].push_back(nul);
	L(i, 1, n) {
		int a, l, r, k;
		cin >> a >> l >> r >> k;
		a = (a + lns) % (n + 1), l = (l + lns) % i + 1, r = (r + lns) % i + 1, k = (k + lns) % (n + 1);
		if(l > r) swap (l, r);
		mexr[0] = i;
		if(!mexl[0]) mexl[0] = i;
		Add (0, i);
		int vl = mexl[a], vr = mexr[a];
		if(vl) {
			int v = seg1 :: query (1, 0, n, a + 1, vr - 1);
			while (v && las[v] >= vl) mexl[v] = las[v] + 1, mexr[v] = vr, vr = las[v], Add (v, i), v = seg1 :: query (1, 0, n, a + 1, vr - 1);
			if(vl <= vr) {
				if(!mexl[v]) mexl[v] = vl;
				mexr[v] = vr;
				Add (v, i);
			}
			mexl[a] = mexr[a] = 0;
			Add (a, i);
		}
		seg1::add (1, 0, n, a, i);
		las[a] = i, lns = 0;
		int z = upper_bound (ti[k].begin(), ti[k].end(), r) - ti[k].begin() - 1;
		lns = (ll) (r - ti[k][z] + 1) * max (hr[k][z] - max (l, hl[k][z]) + 1, 0) + vc[k][z] -> query (l, r);
		cout << lns << '\n';
	}
	return 0;
}