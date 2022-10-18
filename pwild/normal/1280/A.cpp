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

const ll MOD = 1e9 + 7;

void solve() {
	ll x; cin >> x;
	string s; cin >> s;
	
	ll len = sz(s);
	FOR(i,1,x+1) {
		char k = s[i-1]-'1';
		if (sz(s) < x) {
			string t = s.substr(i);
			while (k--) s += t;
			len = sz(s);
		} else {
			len = (len + k * (len-i)) % MOD;
		}
	}
	if (len < 0) len += MOD;
	cout << len << endl;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}