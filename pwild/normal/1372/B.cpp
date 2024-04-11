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

pll solve(ll n) {
	for (ll p = 2; p*p <= n; p++) if (n%p == 0) {
		return {n/p,(p-1)*(n/p)};
	}
	return {1,n-1};
}

pll solve_naive(ll n) {
	pll res(0,n);
	ll best = oo;
	FOR(a,1,n) {
		ll b = n-a, cur = lcm(a,b);
		if (cur < best) best = cur, res = {a,b};
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(n,2,1000) {
		auto [a,b] = solve(n);
		auto [c,d] = solve_naive(n);

		if (lcm(a,b) != lcm(c,d)) {
			cout << n << " " << a << " " << b << " " << c << " " << d << endl;
		}
	}

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		
		auto [a,b] = solve(n);
		cout << a << " " << b << endl;
	}
}