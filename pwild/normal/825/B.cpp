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

ll di[] = {-1,-1,-1,0,0,1,1,1};
ll dj[] = {-1,0,1,-1,1,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n = 10;
	vector<string> a(n);
	FOR(i,0,n) cin >> a[i];
	
	FOR(i,0,n) FOR(j,0,n) FOR(k,0,8) {
		ll cx = 0, cb = 0;
		FOR(d,0,5) {
			ll ni = i+d*di[k], nj = j+d*dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
			if (a[ni][nj] == 'X') cx++;
			if (a[ni][nj] == '.') cb++;
		}
		if (cx == 4 && cb == 1) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}