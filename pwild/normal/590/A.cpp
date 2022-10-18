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
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	auto is_single = [&](ll i) {
		return i > 0 && i+1 < n && a[i] != a[i-1] && a[i] != a[i+1];
	};
	
	ll res = 0;
	FOR(i,0,n) if (is_single(i)) {
		ll j = i;
		while (is_single(j+1)) j++;

		res = max(res, (j-i)/2 + 1);

		if (a[i-1] == a[j+1]) {
			FOR(k,i,j+1) a[k] = a[i-1];
		} else {
			ll m = (i+j+1)/2;
			FOR(k,i,m) a[k] = a[i-1];
			FOR(k,m,j+1) a[k] = a[j+1];
		}
		i = j;
	}

	cout << res << endl;
	FOR(i,0,n) cout << a[i] << " \n"[i+1==n];
}