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

ll di[] = {-1,1,0,0}, dj[] = {0,0,-1,1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n, k; cin >> m >> n >> k;
	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];
	
	ll C = 0;
	vvl comp(m,vl(n,-1));
	vl res;

	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == '.' && comp[i][j] == -1) {
		queue<pll> q;
		comp[i][j] = C;
		res.pb(0);
		q.push({i,j});
		while (sz(q)) {
			ll i, j; tie(i,j) = q.front(); q.pop();
			FOR(k,0,4) {
				ll ni = i+di[k], nj = j+dj[k];
				if (a[ni][nj] == '.' && comp[ni][nj] == -1)
					comp[ni][nj] = C, q.push({ni,nj});
				if (a[ni][nj] == '*') res[C]++;
			}
		}
		C++;
	}
	while (k--) {
		ll i, j; cin >> i >> j;
		i--, j--;
		cout << res[comp[i][j]] << endl;

	}



}