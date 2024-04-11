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

tuple<ll,ll,ll> solve() {
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vl v;
	FOR(i,0,n) if (i == 0 || a[i-1] != a[i]) {
		ll j = i;
		while (j < n && a[j] == a[i]) j++;
		v.pb(j-i);
	}
	
	ll g = v[0], s = 0, b = 0;
	ll i = 1;
	while (i < sz(v) && s <= g) s += v[i++];
	while (i < sz(v) && g+s+b+v[i] <= n/2) b += v[i++];
	
	if (g+s+b > n/2) return {0,0,0};
	if (s <= g || b <= g) return {0,0,0};
	return {g,s,b};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		auto [g,s,b] = solve();
		cout << g << " " << s << " " << b << endl;
	}
}