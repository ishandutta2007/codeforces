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

struct dsu {
	ll n;
	vl p;

	dsu(ll n): n(n), p(n) { iota(all(p),0); }
	
	ll find(ll x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	bool unite(ll x, ll y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		
		if (rand() & 1) swap(x,y);
		p[y] = x;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q;
	cin >> n >> q;

	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll m = 2e5 + 10;
	vl L(m,oo), R(m,-oo), cnt(m);
	FOR(i,0,n) cnt[a[i]]++;
	FOR(i,0,n) R[a[i]] = i;
	FORD(i,0,n) L[a[i]] = i;

	vector<tuple<ll,ll,ll>> intervals;
	FOR(i,0,m) if (L[i] != oo) intervals.eb(L[i],R[i],i);
	sort(all(intervals));

	dsu D(m);
	ll rmax = -1, j = -1;
	for (auto [a,b,i]: intervals) {
		if (a < rmax) D.unite(j,i);
		j = i, rmax = max(rmax,b);
	}

	vl maxsz(m);
	FOR(i,0,m) {
		ll j = D.find(i);
		maxsz[j] = max(maxsz[j], cnt[i]);
	}

	ll res = n;
	FOR(i,0,m) if (D.find(i) == i) res -= maxsz[i];
	cout << res << endl;
}