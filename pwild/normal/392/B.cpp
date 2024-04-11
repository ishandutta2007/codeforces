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
	
vvl costs(vvl cx, vvl cy) {
	vvl res(3,vl(3));
	
	vvl dist(9,vl(9,oo));
	FOR(i,0,9) dist[i][i] = 0;
	FOR(x,0,3) FOR(y,0,3) {
		FOR(nx,0,3) if (nx != x) dist[3*x+y][3*nx+y] = cx[x][nx];
		FOR(ny,0,3) if (ny != y && y != x && ny != x)
								 dist[3*x+y][3*x+ny] = cy[y][ny];
	}

	FOR(k,0,9) FOR(i,0,9) FOR(j,0,9) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

	FOR(i,0,3) FOR(j,0,3) res[i][j] = dist[4*i][4*j];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vvl s(3,vl(3));
	FOR(i,0,3) FOR(j,0,3) cin >> s[i][j];
	ll n; cin >> n;

	vector<vvl> t(n+1);
	t[0] = vvl(3,vl(3));
	FOR(m,1,n+1) t[m] = costs(t[m-1],s);

	cout << t[n][0][2] << endl;

}