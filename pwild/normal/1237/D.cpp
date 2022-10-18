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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vector<pll> v(n);
	FOR(i,0,n) v[i] = {a[i],i};
	sort(all(v));

	vl fail(n);
	
	ll l = 0;
	set<ll> is;
	FOR(r,0,n) {
		while (2*v[l].xx < v[r].xx) {
			is.insert(v[l++].yy);
		}
		ll i = v[r].yy;
		auto it = is.upper_bound(i);
		if (it == end(is)) it = begin(is);
		fail[i] = it != end(is) ? *it : -1;
	}
	
	auto dist = [&](ll i, ll j) {
		return i < j ? j-i : j-i+n;
	};

	vl res(n,oo);

	is.clear();
	reverse(all(v));
	FOR(r,0,n) {
		ll i = v[r].yy;
		auto it = is.upper_bound(i);
		if (it == end(is)) it = begin(is);
		
		if (it != end(is)) {
			ll j = *it;
			res[i] = min(res[i], dist(i,j) + res[j]);
		}
		if (fail[i] != -1) {
			res[i] = min(res[i], dist(i,fail[i]));
		}
		is.insert(i);
	}
	FOR(i,0,n) if (res[i] == oo) res[i] = -1;
	FOR(i,0,n) cout << res[i] << " \n"[i+1==n];
}