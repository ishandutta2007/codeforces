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
	
	ll n, k;
	cin >> n >> k;

	string s; cin >> s;
	vl a(n);
	FOR(i,0,n) a[i] = s[i] == 'R';

	vvl res;
	while (true) {
		vl b = a, cur;
		FOR(i,0,n-1) if (a[i] && !a[i+1]) swap(b[i],b[i+1]), cur.pb(i+1);
		a = b;
		if (sz(cur)) res.pb(cur);
		else break;
	}

	ll kmin = sz(res), kmax = 0;
	for (auto &v: res) kmax += sz(v);

	if (k < kmin || k > kmax) {
		cout << -1 << endl;
		return 0;
	}

	vvl nres;
	k -= kmin;
	for (auto &v: res) {
		ll take = min(k, sz(v)-1);
		k -= take;
		FOR(i,0,take) nres.pb(vl(1,v[i]));
		nres.pb(vl(begin(v)+take,end(v)));
	}
	assert(k == 0);

	for (auto &v: nres) {
		cout << sz(v);
		for (ll x: v) cout << " " << x;
		cout << '\n';
	}
}