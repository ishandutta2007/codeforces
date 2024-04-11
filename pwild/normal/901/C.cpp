#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

struct node {
	ll cnt = 0, lo = oo, hi = -oo, sum = 0;
	node(ll x): cnt(1), lo(x), hi(x), sum(x) { }
	node(ll cnt, ll lo, ll hi, ll sum): cnt(cnt), lo(lo), hi(hi), sum(sum) { }
	node operator+(node n) {
		return {cnt+n.cnt, min(lo,n.lo), max(hi,n.hi), sum+n.sum};
	}
};

const ll N = 1.3e6;
//node tree[N];


struct bcc {
	ll n, vC = 0, eC = 0, T = 0, top = -1;
	vl ecc, t, st;
	vvl adj;
	
	ll dfs(ll i, ll p = -1) {
		ll tmin = t[i] = T++;
		st[++top] = i;
		for (ll j: adj[i]) if (j != p) {
			ll ntmin = t[j];
			if (t[j] == -1) {
				ntmin = dfs(j,i);
				if (ntmin > t[i]) {
					while (st[top] != j) ecc[st[top--]] = eC;
					ecc[st[top--]] = eC++;
				}
			}
			tmin = min(tmin, ntmin);
		}
		return tmin;
	}
	
	bcc(vvl adj): n(sz(adj)), ecc(n,-1), t(n,-1), st(n), adj(adj) {
		FOR(i,0,n) if (t[i] < 0) {
			dfs(i);
			while (st[top] != 0) ecc[st[top--]] = eC;
			ecc[i] = eC++;
		}
	}
};

const ll BLOCK = 500;

struct query {
	ll a, b, i;
	bool operator<(const query &q) const {
		if (a/BLOCK != q.a/BLOCK) return a < q.a;
		return b < q.b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	vvl adj(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	bcc B(adj);
	
	ll C = B.eC;
	vl lo(C), hi(C);
	FORD(i,0,n) lo[B.ecc[i]] = i;
	FOR(i,0,n)  hi[B.ecc[i]] = i;

	vl max_ok(n,n);
	FOR(c,0,C) if (lo[c] < hi[c]) {
		max_ok[lo[c]] = hi[c];
	}
	FORD(i,0,n-1) max_ok[i] = min(max_ok[i],max_ok[i+1]);
	
	vl sum(n+1);
	FOR(i,0,n) sum[i+1] = sum[i] + max_ok[i]-i;
	
	ll q; cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		a--;
		
		ll c = lower_bound(all(max_ok),b) - begin(max_ok);
		c = min(c,b);
		c = max(a,c);

		ll res = sum[c]-sum[a] + (b-c)*(b-c+1)/2;
		cout << res << endl;
	}

}