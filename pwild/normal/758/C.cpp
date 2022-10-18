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

ll n, m, k, x, y;

void solve1() {
	ll res = k/m;
	if (k % m == 0) {
		cout << res << " " << res << " " << res << endl;
	} else {
		cout << res+1 << " " << res << " " << (res+ (y < k%m)) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k >> x >> y;
	x--, y--;

	if (n == 1) {
		solve1();
	} else if (n == 2) {
		y += x*m;
		n /= 2, m *= 2;
		solve1();
	} else {
		ll p = 2*(n-1)*m;
		
		vvl cnt(n, vl(m));
		FOR(j,0,m) cnt[0][j] = cnt[n-1][j] = k/p;
		FOR(i,1,n-1) FOR(j,0,m) cnt[i][j] = 2*(k/p);

		k %= p;
		ll ii = 0;
		FOR(i,0,n-1) FOR(j,0,m) {
			if (ii < k) cnt[i][j]++;
			ii++;
		}
		FORD(i,1,n) FOR(j,0,m) {
			if (ii < k) cnt[i][j]++;
			ii++;
		}
		
		ll rmax = 0, rmin = oo;
		FOR(i,0,n) FOR(j,0,m) rmax = max(rmax,cnt[i][j]);
		FOR(i,0,n) FOR(j,0,m) rmin = min(rmin,cnt[i][j]);
		
		cout << rmax << " " << rmin << " " << cnt[x][y] << endl;
	}
}