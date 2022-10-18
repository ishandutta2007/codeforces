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

void fail() {
	cout << "Impossible" << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll a[2][2];
	FOR(i,0,2) FOR(j,0,2) cin >> a[i][j];
	ll sum = 0;
	FOR(i,0,2) FOR(j,0,2) sum += a[i][j];
	
	if (!sum) {
		cout << "0" << endl;
		return 0;
	}

	ll n = 0;
	while (n*(n-1)/2 < sum) n++;
	if (n*(n-1)/2 > sum) fail();
	
	if (a[0][0] == sum) {
		cout << string(n,'0') << endl;
		return 0;
	}
	if (a[1][1] == sum) {
		cout << string(n,'1') << endl;
		return 0;
	}

	for (ll n0 = 1; n0*(n0-1)/2 <= a[0][0]; n0++) if (n0*(n0-1)/2 == a[0][0]) {
		for (ll n1 = 1; n1*(n1-1)/2 <= a[1][1]; n1++) if (n1*(n1-1)/2 == a[1][1]) {
			if (n0 + n1 != n) continue;
			FOR(i,0,a[0][1]/n1) cout << '0';
			FOR(i,0,n1 - a[0][1]%n1) cout << '1';
			if (a[0][1]/n1 < n0) cout << '0';
			FOR(i,0,a[0][1]%n1) cout << '1';
			FOR(i,0,n0 - 1 - a[0][1]/n1) cout << '0';
			cout << endl;
			return 0;
		}
	}
	fail();
}