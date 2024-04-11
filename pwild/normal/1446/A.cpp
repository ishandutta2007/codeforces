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
		ll n, s;
		cin >> n >> s;
		vector<pll> a(n);
		FOR(i,0,n) cin >> a[i].xx, a[i].yy = i+1;
		sort(all(a));
		while (n > 0 && a[n-1].xx > s) a.pop_back(), n--;
		
		if (n == 0) {
			cout << -1 << endl;
			continue;
		}

		reverse(all(a));
		
		vl res;
		ll t = 0;
		for (auto [w,i]: a) {
			res.pb(i), t += w;
			if (t >= (s+1)/2) break;
		}
		assert(t <= s);

		if (t >= (s+1)/2) {
			cout << sz(res) << endl;
			for (ll i: res) cout << i << " ";
			cout << endl;
		} else {
			cout << -1 << endl;
		}

	}


}