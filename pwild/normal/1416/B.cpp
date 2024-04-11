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

void solve() {
	ll n; cin >> n;
	vl a(n+1);
	FOR(i,1,n+1) cin >> a[i];

	ll s = accumulate(all(a),0LL);
	if (s%n != 0) {
		cout << -1 << "\n";
		return;
	}
	
	vector<tuple<ll,ll,ll>> res;

	auto add = [&](ll i, ll j, ll x) {
		a[i] -= i*x, a[j] += i*x;
		res.eb(i,j,x);
		assert(a[i] >= 0);
	};

	FOR(i,2,n+1) {
		ll r = (i-a[i]%i)%i;
		if (r) add(1,i,r);
		add(i,1,a[i]/i);
		assert(a[i] == 0);
	}
	
	FOR(i,2,n+1) add(1,i,s/n);

	cout << sz(res) << "\n";
	for (auto [i,j,x]: res) cout << i << " " << j << " " << x << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}