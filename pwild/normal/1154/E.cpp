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

	vl s(n);
	FOR(i,0,n) cin >> s[i];

	set<pll> si, is;
	FOR(i,0,n) si.emplace(s[i],i);
	FOR(i,0,n) is.emplace(i,s[i]);
	
	string res(n,'0');
	FOR(t,0,oo) {
		if (si.empty()) break;
		ll i = si.rbegin()->yy;
		auto it = is.find({i,s[i]});
		auto lit = it, rit = it;
		FOR(t,0,k) if (lit != begin(is)) lit--;
		FOR(t,0,k+1) if (rit != end(is)) rit++;
		for (it = lit; it != rit; it++) {
			ll j = it->xx;
			si.erase({s[j],j});
			res[j] = '1' + t%2;
		}
		is.erase(lit,rit);
	}
	cout << res << endl;
}