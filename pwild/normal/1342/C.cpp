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
		ll a, b, q;
		cin >> a >> b >> q;

		ll n = a*b;
		vl v(n);
		FOR(i,0,n) v[i] = i%a%b != i%b%a;

		vl s(n+1);
		FOR(i,0,n) s[i+1] = s[i] + v[i];

		auto f = [&](ll i) {
			return (i/n) * s[n] + s[i%n];
		};

		while (q--) {
			ll lo, hi;
			cin >> lo >> hi;
			cout << f(hi+1) - f(lo);
			if (q) cout << ' ';
		}
		cout << endl;
	}
}