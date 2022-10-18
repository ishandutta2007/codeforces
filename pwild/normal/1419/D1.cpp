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

ll solve_naive(vl a) {
	ll n = sz(a), res = 0;
	sort(all(a));
	do {
		ll cur = 0;
		FOR(i,1,n-1) cur += a[i] < a[i-1] && a[i] < a[i+1];
		res = max(res, cur);
	} while (next_permutation(all(a)));
	return res;
}

ll solve(vl a, bool print = false) {
	ll n = sz(a), res = 0;
	sort(all(a));
	vl b(n);
	FOR(i,0,n/2) b[2*i+1] = a[i];
	FOR(i,n/2,n) b[2*(i-n/2)] = a[i];

	FOR(i,1,n-1) res += b[i] < b[i-1] && b[i] < b[i+1];

	if (print) {
		cout << res << endl;
		for (ll x: b) cout << x << " ";
		cout << endl;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*
	FOR(tc,0,10000) {
		cout << tc << endl;
		ll n = 1 + rand() % 10;
		vl a(n);
		FOR(i,0,n) a[i] = rand() % 10;
		if (solve(a) != solve_naive(a)) {
			for (ll x: a) cout << x << " ";
			cout << endl;
			return 0;
		}
	}
	*/

	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	solve(a,true);
}