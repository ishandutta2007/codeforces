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
	
	string s; cin >> s;
	
	set<ll> zero_end, one_end;
	vvl res;
	
	ll ind = 1;
	for (char c: s) {
		if (c == '0') {
			if (one_end.empty()) {
				ll k = sz(res);
				res.pb({ind});
				zero_end.insert(k);
			} else {
				ll k = *begin(one_end);
				one_end.erase(k);
				zero_end.insert(k);
				res[k].pb(ind);
			}
		} else {
			if (zero_end.empty()) {
				cout << -1 << endl;
				return 0;
			} else {
				ll k = *begin(zero_end);
				zero_end.erase(k);
				one_end.insert(k);
				res[k].pb(ind);
			}
		}
		ind++;
	}
	
	if (!one_end.empty()) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << sz(res) << endl;
	for (vl a: res) {
		cout << sz(a);
		for (ll x: a) cout << " " << x;
		cout << endl;
	}

}