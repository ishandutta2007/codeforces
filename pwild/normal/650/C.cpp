#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

vl p;

ll Find(ll x) {
	if (x == p[x]) return x;
	return p[x] = Find(p[x]);
}
bool Union(ll x, ll y) {
	x = Find(x), y = Find(y);
	if (x == y) return false;
	if (rand() & 1) swap(x,y);
	p[x] = y;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n; cin >> m >> n;
	vvl a(m,vl(n));
	FOR(i,0,m) FOR(j,0,n) cin >> a[i][j];
	
	vector<pair<ll,pll>> v(m*n);
	FOR(i,0,m) FOR(j,0,n) v[i*n+j] = mp(a[i][j],mp(i,j));
	sort(all(v));

	ll C = 0;
	vvl comp(m,vl(n,-1));
	p = vl(m*n);
	FOR(i,0,m*n) p[i] = i;

	vl imax(m), jmax(n);
	
	vl i2c(m,-1), j2c(n,-1);
	
	FOR(i,0,m*n) {
		ll j = i;
		while (j < m*n && v[j].xx == v[i].xx) j++;
		
		FOR(k,i,j) {
			ll x, y; tie(x,y) = v[k].yy;
			comp[x][y] = C++;
			if (i2c[x] != -1) Union(i2c[x],comp[x][y]);
			else i2c[x] = comp[x][y];
			if (j2c[y] != -1) Union(j2c[y],comp[x][y]);
			else j2c[y] = comp[x][y];
		}
		FOR(k,i,j) {
			ll x, y; tie(x,y) = v[k].yy;
			i2c[x] = j2c[y] = -1;
			v[k].xx = Find(comp[x][y]);
		}
		i = j-1;
	}
	sort(all(v));

	FOR(i,0,m*n) {
		ll j = i;
		while (j < m*n && v[j].xx == v[i].xx) j++;

		ll cur = 0;
		FOR(k,i,j) cur = max(cur,max(imax[v[k].yy.xx],jmax[v[k].yy.yy]));
		cur++;
		FOR(k,i,j) {
			a[v[k].yy.xx][v[k].yy.yy] = cur;
			imax[v[k].yy.xx] = cur;
			jmax[v[k].yy.yy] = cur;
		}		
		i = j-1;
	}
	
	FOR(i,0,m) FOR(j,0,n) cout << a[i][j] << " \n"[j+1==n];


}