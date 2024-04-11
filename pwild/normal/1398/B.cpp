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
	
	ll tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		vl a;
		ll n = sz(s);
		FOR(i,0,n) if (s[i] == '1' && (i == 0 || s[i-1] == '0')) {
			ll j = i;
			while (j < n && s[j] == '1') j++;
			a.pb(j-i);
		}
		sort(all(a), greater<ll>());
		
		ll res = 0;
		for (ll i = 0; i < sz(a); i += 2) res += a[i];
		cout << res << endl;
	}
}