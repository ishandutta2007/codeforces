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
	
	ll n, m;
	cin >> n >> m;

	dsu D(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		D.unite(a,b);
	}
	
	vl lo(n,n), hi(n,-1);
	FOR(i,0,n) {
		ll j = D.find(i);
		lo[j] = min(lo[j],i);
		hi[j] = max(hi[j],i);
	}
	
	ll C = 0;
	vl v(n);
	FOR(i,0,n) if (D.find(i) == i) {
		C++;
		v[lo[i]]++;
		v[hi[i]]--;
	}
	
	ll B = 0, sum = 0;
	FOR(i,0,n) {
		sum += v[i];
		if (sum == 0) B++;
	}
	
	cout << C-B << endl;
}