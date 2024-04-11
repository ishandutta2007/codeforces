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

ll solve_min(vl a) {
	ll n = sz(a);

	ll res = 0;
	for (ll i = 0; i < n; ) {
		ll j = i;
		while (j < n && a[j] <= a[i]+2) j++;
		res++, i = j;
	}
	return res;
}

ll solve_max(vl a) {
	ll n = sz(a);

	ll res = 0, prev = -10;
	FOR(i,0,n) {
		FOR(d,-1,2) if (a[i]+d > prev) {
			a[i] += d;
			prev = a[i];
			break;
		}
	}
	
	sort(all(a));
	return unique(all(a))-begin(a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));
	
	cout << solve_min(a) << " " << solve_max(a) << endl;
}