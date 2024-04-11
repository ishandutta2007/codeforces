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

const ll N = 500;

vvl brute(ll x, ll y, ll z) {
	vl take = {x,y,z};
	vvl g(N,vl(3));
	FOR(n,1,N) FOR(k,0,3) {
		set<ll> s;
		FOR(i,0,3) {
			if (k > 0 && i == k) continue;
			s.insert(g[max(0LL,n-take[i])][i]);
			while (s.count(g[n][k])) g[n][k]++;
		}
	}
	return g;
}

ll period(vvl g) {
	vl hashes;
	ll n = sz(g);
	FOR(k,N/2,n-5) {
		ll hash = 0;
		FOR(i,k,k+5) FOR(j,0,3) {
			hash = 4*hash + g[i][j];
		}
		hashes.pb(hash);
	}
	
	FOR(p,1,sz(hashes)) if (hashes[p] == hashes[0]) {
		FOR(i,p+1,sz(hashes)) assert(hashes[i] == hashes[i-p]);
		return p;
	}
	
	return oo;
}

void solve() {
	ll n, x, y, z;
	cin >> n >> x >> y >> z;
	vl take = {x,y,z};

	vvl gg = brute(x,y,z);
	ll p = period(gg);
	auto g = [&](ll i, ll j) {
		if (i < N/2) return gg[i][j];
		i = N/2 + (i-N/2)%p;
		return gg[i][j];
	};

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll G = 0;
	FOR(i,0,n) G ^= g(a[i], 0);
	
	ll res = 0;
	FOR(i,0,n) FOR(j,0,3) {
		ll nG = G ^ g(a[i], 0) ^ g(max(0LL,a[i]-take[j]), j);
		if (nG == 0) res++;
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	FOR(x,1,6) FOR(y,1,6) FOR(z,1,6) {
//		cerr << x << " " << y << " " << z << " " << period(brute(x,y,z)) << endl;
	}

	ll tc; cin >> tc;
	while (tc--) solve();
}