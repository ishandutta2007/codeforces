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

void fail() {
	cout << "NO" << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q;
	cin >> n >> q;
	
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	bool has_max = find(all(a),q) != end(a);

	FOR(i,0,n) if (a[i] == 0) {
		if (!has_max) {
			a[i] = q;
			has_max = true;
		} else {
			a[i] = i > 0 ? a[i-1] : 1;
		}
	}
	
	if (!has_max) fail();
	
	set<ll> S = {n};
	vector<pll> v(n);
	FOR(i,0,n) v[i] = {a[i],i};
	sort(all(v));
	
	FOR(i,0,n-1) {
		if (v[i].xx == v[i+1].xx) {
			ll j = *S.lower_bound(v[i].yy);
			if (j < v[i+1].yy) fail();
		}
		S.insert(v[i].yy);
	}
	
	cout << "YES" << endl;
	FOR(i,0,n) cout << a[i] << " \n"[i+1==n];

}