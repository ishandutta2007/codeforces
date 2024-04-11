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

ll dist(ll x, ll y) { return x+y; } // x*x + y*y; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n;
	cin >> m >> n;

	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];

	ll i = 0, j = 0, res = 0;
	while (i+1 < m || j+1 < n) {
		res += a[i][j] == '*';
		a[i][j] = '.';
		/*
		if (j+1 < n && a[i][j+1] == '*') {
			j++;
		} else if (i+1 < m && a[i+1][j] == '*') {
			i++;
		} else if (j+1 < n) {
			j++;
		} else {
			i++;
		} */
		
		ll ni = m, nj = n;
		FOR(oi,i,m) FOR(oj,j,n) if (a[oi][oj] == '*') {
			if (dist(oi-i,oj-j) < dist(ni-i,nj-j)) {
				ni = oi, nj = oj;
			}
		}

		i = ni, j = nj;

/*
		ll ni = i+1, nj = j+1;
		while (ni < m && a[ni][j] == '.') ni++;
		while (nj < n && a[i][nj] == '.') nj++;
		
		ll disti = ni == m ? oo : ni-i;
		ll distj = nj == n ? oo : nj-j;
		
		if (min(disti,distj) == oo) {
			if (j+1 < n) j++; else i++;
		} else if (distj < oo) { // disti < distj) {
			i++;
		} else {
			j++;
		}*/
	}
	res += a[m-1][n-1] == '*';
	cout << res << endl;
}