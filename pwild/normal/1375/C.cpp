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

bool solve_naive(vl a) {
	if (sz(a) == 1) return true;
	
	vl del(sz(a));
	FOR(i,0,sz(a)-1) if (a[i] < a[i+1]) {
		del[i] = del[i+1] = 1;
	}
	
	FOR(i,0,sz(a)) if (del[i]) {
		vl b = a;
		b.erase(begin(b)+i);
		if (solve_naive(b)) return true;
	}
	return false;
}

bool solve(vl a) {
	ll n = sz(a), lo = oo;
	return a[0] < a[n-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*
	FOR(n,2,8) {
		vl a(n);
		iota(all(a),1);
		do {
			ll x = solve(a);
			ll y = solve_naive(a);
			if (x != y) {
				FOR(i,0,n) cout << a[i] << " ";
				cout << "| " << x << " " << y << endl;
			}
		} while (next_permutation(all(a)));
	}
	*/

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;

		vl a(n);
		FOR(i,0,n) cin >> a[i];
		
		cout << (solve(a) ? "YES" : "NO") << endl;
	}
}