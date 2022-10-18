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
	ll n, k;
	cin >> n >> k;

	string a; cin >> a;

	if (a == string(n,'L')) {
		cout << max(0LL,2*k-1) << endl;
		return;
	}

	ll extra = 0;
	while (a[extra] == 'L') extra++;
	vl gaps;
	FOR(i,0,n-1) if (a[i] == 'W' && a[i+1] == 'L') {
		ll j = i+1;
		while (j < n && a[j] == 'L') j++;
		if (j < n) gaps.pb(j-i-1);
		else extra += j-i-1;
	}
	sort(all(gaps));

	ll res = 0;
	FOR(i,0,n) if (a[i] == 'W') {
		res += 1 + (i > 0 && a[i-1] == 'W');
	}
	
	for (ll x: gaps) {
		ll take = min(k,x);
		res += 2*take;
		res += take == x;
		k -= take;
	}
	res += 2*min(k,extra);
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}