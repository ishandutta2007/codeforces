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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

ll id(char c) {
	if (c == '?') return 26;
	return c-'a';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	string a, b;
	cin >> a >> b;

	vvl occa(27), occb(27);
	FOR(i,0,n) occa[id(a[i])].pb(i+1);
	FOR(i,0,n) occb[id(b[i])].pb(i+1);
	
	vector<pll> res;
	auto add_pairs = [&](vl &v, vl &w) {
		ll k = min(sz(v),sz(w));
		while (k--) {
			res.eb(v.back(),w.back());
			v.pop_back();
			w.pop_back();
		}
	};

	FOR(c,0,26) add_pairs(occa[c],occb[c]);
	FOR(c,0,26) add_pairs(occa[26],occb[c]);
	FOR(c,0,26) add_pairs(occa[c],occb[26]);
	add_pairs(occa[26],occb[26]);
	
	cout << sz(res) << endl;
	for (pll p: res) cout << p.xx << " " << p.yy << endl;

}