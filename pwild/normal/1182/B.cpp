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

void fail() {
	cout << "NO" << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n;
	cin >> m >> n;
	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];

	ll r = -1, c = -1;
	FOR(i,0,m) {
		ll cnt = 0;
		FOR(j,0,n) cnt += a[i][j] == '*';
		if (cnt > 1) {
			if (r != -1) fail();
			else r = i;
		}
	}
	FOR(j,0,n) {
		ll cnt = 0;
		FOR(i,0,m) cnt += a[i][j] == '*';
		if (cnt > 1) {
			if (c != -1) fail();
			else c = j;
		}
	}
	
	if (r == -1 || c == -1) fail();
	if (a[r][c] == '.') fail();
	
	ll imin = r, imax = r, jmin = c, jmax = c;
	while (imin > 0   && a[imin-1][c] == '*') imin--;
	while (imax < m-1 && a[imax+1][c] == '*') imax++;
	while (jmin > 0   && a[r][jmin-1] == '*') jmin--;
	while (jmax < n-1 && a[r][jmax+1] == '*') jmax++;
	
	if (imin == r || imax == r) fail();
	if (jmin == c || jmax == c) fail();

	FOR(i,0,m) FOR(j,0,n) {
		if (i < imin || i > imax || j < jmin || j > jmax) {
			if (a[i][j] == '*') fail();
		} else {
			if ((a[i][j] == '*') != (i == r || j == c)) fail();
		}
	}
	cout << "YES" << endl;
}