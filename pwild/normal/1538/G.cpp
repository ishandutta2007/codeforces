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

ll solve(ll x, ll y, ll a, ll b) {
	if (a == b) return min(x,y)/a;
	if (a > b) swap(x,y), swap(a,b);

	ll lo = 0, hi = (x+y)/(a+b) + 1;
	
	auto can = [&](ll n) {
		ll c = x - n*a, d = y - n*a;
		if (min(c,d) < 0) return false;
		ll k = c/(b-a) + d/(b-a);
		return k >= n;
	};

	while (hi-lo > 1) {
		ll md = (lo+hi)/2;
		if (can(md)) lo = md; else hi = md;
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		cout << solve(x,y,a,b) << endl;
	}
}