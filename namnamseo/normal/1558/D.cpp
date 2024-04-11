#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;
const int mod = 998'244'353;

int n, m;

int fact[maxn*2];
int finv[maxn*2];
ll ipow(ll b, ll e) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		(b *= b) %= mod; e /= 2;
	}
	return ret;
}
void Build() {
	const int t = int(4e5);
	fact[0] = 1;
	for (int i=1; i<=t; ++i) {
		fact[i] = fact[i-1]*1ll*i%mod;
	}
	finv[t] = ipow(fact[t], mod-2);
	for (int i=t; 1<=i; --i) {
		finv[i-1] = finv[i]*1ll*i%mod;
	}
}

int C(int n, int r) {
	if (r<0 || r>n) return 0;
	return fact[n] * 1ll * finv[r] % mod * finv[n-r] % mod;
}

int H(int n, int r) {
	return C(n+r-1, r);
}

struct Node {
	int c[2], p;
	int val, lz;
	int oi;
} nd[maxn];
int root;
int nn;

inline void flush(int vi) {
	auto &v = nd[vi];
	int tmp = v.lz;
	if (!tmp) return;
	rep(i, 2) if (v.c[i]) {
		auto &h = nd[v.c[i]];
		h.val += tmp;
		h.lz += tmp;
	}
	v.lz = 0;
}

int isang(int vi, int k) {
	if (!vi) return -1;
	auto &v = nd[vi];
	flush(vi);
	if (v.val < k) { return isang(v.c[1], k); }
	int tmp = isang(v.c[0], k);
	if (tmp == -1) return vi;
	return tmp;
}

inline void rot(int x) {
	int p = nd[x].p, w = (nd[p].c[1] == x);
	int pp = nd[p].p, ww = (nd[pp].c[1] == p);

	flush(p); flush(x);
	int t = nd[x].c[!w];
	nd[p].c[w] = t; if (t) nd[t].p = p;
	nd[x].c[!w] = p; nd[p].p = x;
	nd[x].p = pp; if (pp) nd[pp].c[ww] = x;
}

void splay(int x) {
	while (nd[x].p) {
		int p = nd[x].p, w = (nd[p].c[1] == x);
		int pp = nd[p].p, ww = (nd[pp].c[1] == p);
		if (!pp) { rot(x); break; }
		if (w == ww) rot(p), rot(x);
		else rot(x), rot(x);
	}
	root = x;
}

void add_just_before(int vi, int nvi) {
	flush(vi);
	if (!nd[vi].c[0]) {
		nd[vi].c[0] = nvi;
		nd[nvi].p = vi;
		return;
	}
	vi = nd[vi].c[0]; flush(vi);
	while (nd[vi].c[1]) vi = nd[vi].c[1], flush(vi);
	nd[vi].c[1] = nvi;
	nd[nvi].p = vi;
}

void add_last(int vi, int nvi) {
	flush(vi);
	while (nd[vi].c[1]) vi = nd[vi].c[1], flush(vi);
	nd[vi].c[1] = nvi;
	nd[nvi].p = vi;
}

int Find(int vi, int k) {
	if (!vi) return -1;

	if (nd[vi].val == k) return vi;
	flush(vi);
	if (nd[vi].val < k) {
		return Find(nd[vi].c[1], k);
	} else {
		return Find(nd[vi].c[0], k);
	}
}

bool is_strong[maxn];

void Work() {
	cin >> n >> m;
	nn = root = 0;
	for (int i=0; i<m; ++i) {
		int x, y; cin >> x >> y;
		int v = ++nn;
		nd[v] = {{0, 0}, 0, y, 0, x};
		if (!root) { root = v; is_strong[0]=1; continue; }
		int iv = isang(root, y);
		if (iv == -1) {
			add_last(root, v);
		} else {
			splay(iv);
			add_just_before(iv, v);
			splay(v);
			nd[iv].val += 1;
			nd[iv].lz += 1;
		}

		int tmp = Find(root, y-1);
		if (tmp != -1) {
			splay(tmp);
			is_strong[tmp-1] = false;
		}
		is_strong[i] = true;
	}

	int strongs = 0;
	for (int i=0; i<m; ++i) if (is_strong[i]) strongs++;

	int ans = H(n+1, n-1-strongs);
	cout << ans << '\n';
}

int main()
{
	cppio();
	Build();

	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}