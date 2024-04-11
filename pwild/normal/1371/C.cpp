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

bool solve_naive(ll a, ll b, ll m, ll n) {
	FOR(mask,0,1 << (m+n)) if (__builtin_popcount(mask) == m) {
		ll c = a, d = b;
		FOR(i,0,m+n) {
			if (mask & (1 << i)) {
				(c > d ? c : d)--;
			} else {
				(c > d ? d : c)--;
			}
		}
		if (c >= 0 && d >= 0) return true;
	}
	return false;
}

bool solve(ll a, ll b, ll m, ll n) {
	if (a+b < m+n) return false;
	if (min(a,b) < n) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	/*
	FOR(a,0,8) FOR(b,0,8) FOR(m,0,8) FOR(n,0,8) if (m+n) {
		ll x = solve(a,b,m,n), y = solve_naive(a,b,m,n);
		if (x != y) printf("%d %d %d %d %d %d\n", a, b, m, n, x, y);
	}
	*/

	ll tc; cin >> tc;
	while (tc--) {
		ll a, b, m, n;
		cin >> a >> b >> m >> n;
		cout << (solve(a,b,m,n) ? "Yes" : "No") << endl;
	}
}