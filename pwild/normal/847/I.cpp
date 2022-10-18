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

const ll N = 300;
ll dist[N][N];
ll x[N*N], y[N*N];
ll sp, ep;

const ll di[] = {-1,1,0,0}, dj[] = {0,0,-1,1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dist,-1,sizeof dist);


	ll m, n, q, p;
	cin >> m >> n >> q >> p;
	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];
	

	vvl res(m,vl(n));
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] != '.') {
		if (a[i][j] == '*') continue;
		vl lvl = {(a[i][j]-'A'+1) * q};
		while (lvl.back()) lvl.pb(lvl.back()/2);
		lvl.pop_back();
		
		sp = ep = 0;
		dist[i][j] = 0;
		x[ep] = i, y[ep++] = j;

		while (sp < ep) {
			ll ci = x[sp], cj = y[sp++];
			
			if (dist[ci][cj] == sz(lvl)-1) continue;

			FOR(k,0,4) {
				ll ni = ci+di[k], nj = cj+dj[k];
				if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
				if (a[ni][nj] == '*') continue;
				if (dist[ni][nj] != -1) continue;
				dist[ni][nj] = dist[ci][cj]+1;
				x[ep] = ni, y[ep++] = nj;
			}
		}

		FOR(pp,0,ep) {
			ll ci = x[pp], cj = y[pp];
			//cerr << ci << " " << cj << " " << dist[ci][cj] << endl;
			res[ci][cj] += lvl[dist[ci][cj]];
			dist[ci][cj] = -1;
		}
	}
	
	ll ans = 0;
	FOR(i,0,m) FOR(j,0,n) {
		//cout << res[i][j] << " \n"[j+1==n];
		ans += res[i][j] > p;
	}
	cout << ans << endl;
}