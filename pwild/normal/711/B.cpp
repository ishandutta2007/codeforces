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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vvl a(n,vl(n));
	FOR(i,0,n) FOR(j,0,n) cin >> a[i][j];

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	ll i0, j0;
	FOR(i,0,n) FOR(j,0,n) if (a[i][j] == 0) i0 = i, j0 = j;
	
	ll sum0 = 0, sum1 = 0;
	FOR(i,0,n) sum0 += a[i][j0], sum1 += a[i][!j0];

	FOR(i,0,n) {
		ll cur = 0;
		FOR(j,0,n) cur += a[i][j];
		if (i == i0) {
			if (cur != sum0) {
				cout << -1 << endl;
				return 0;
			}
		} else {
			if (cur != sum1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	FOR(j,0,n) {
		ll cur = 0;
		FOR(i,0,n) cur += a[i][j];
		if (j == j0) {
			if (cur != sum0) {
				cout << -1 << endl;
				return 0;
			}
		} else {
			if (cur != sum1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	ll cur = 0;
	FOR(i,0,n) cur += a[i][i];
	if (i0 == j0) {
		if (cur != sum0) {
			cout << -1 << endl;
			return 0;
		}
	} else {
		if (cur != sum1) {
			cout << -1 << endl;
			return 0;
		}
	}
	cur = 0;
	FOR(i,0,n) cur += a[i][n-1-i];
	if (i0 + j0 == n-1) {
		if (cur != sum0) {
			cout << -1 << endl;
			return 0;
		}
	} else {
		if (cur != sum1) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	ll res = sum1 - sum0;
	if (res <= 0 || res > ll(1e18)) cout << -1 << endl;
	else cout << res << endl;

}