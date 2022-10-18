#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f;
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

ll di[] = {1,0,-1,0}, dj[] = {0,1,0,-1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, x; cin >> m >> n >> x;
	
	vvl a(m,vl(n));
	vector<vector<pll>> b(x+1);
	FOR(i,0,m) FOR(j,0,n) {
		cin >> a[i][j];
		b[a[i][j]].eb(i,j);
	}
	
	vvl d(m,vl(n,oo));
	for (const auto &p : b[1]) d[p.xx][p.yy] = p.xx + p.yy;

	FOR(k,1,x) {
		cerr << k << endl;
		if (sz(b[k]) > 1000) {
			vvl dd(m,vl(n,oo));
			set<pair<ll,pll>> q;
			for (const auto &p : b[k]) {
				ll i, j; tie(i,j) = p;
				dd[i][j] = d[i][j], q.insert(mp(d[i][j],p));
			}
			while (sz(q)) {
				ll i, j; tie(i,j) = begin(q)->yy;
				q.erase(begin(q));
				FOR(t,0,4) {
					ll ni = i+di[t], nj = j+dj[t];
					if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
					if (dd[ni][nj] < dd[i][j] + 1) continue;
					q.erase(mp(dd[ni][nj],mp(ni,nj)));
					dd[ni][nj] = dd[i][j] + 1;
					q.insert(mp(dd[ni][nj],mp(ni,nj)));
				}
			}
			for (const auto &p : b[k+1]) d[p.xx][p.yy] = dd[p.xx][p.yy];
		} else {
			for (const auto &p : b[k]) {
				ll i, j; tie(i,j) = p;
				for (const auto &np : b[k+1]) {
					ll ni, nj; tie(ni,nj) = np;
					d[ni][nj] = min(d[ni][nj],d[i][j] + abs(i-ni) + abs(j-nj));
				}
			}
		}
	}
	ll res = oo;
	for (const auto &p : b[x]) res = min(res,d[p.xx][p.yy]);
	cout << res << endl;
}