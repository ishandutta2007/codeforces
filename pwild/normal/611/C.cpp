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

const ll maxN = 510;

string a[maxN];
ll sumh[maxN][maxN], sumv[maxN][maxN], sum[maxN][maxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n; cin >> m >> n;
	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];
	
	FOR(i,0,m) FOR(j,0,n) {
		if (i > 0) sumv[i][j] += sumv[i-1][j] + (a[i][j] == '.' && a[i-1][j] == '.');
		if (j > 0) sumv[i][j] += sumv[i][j-1];
		if (i > 0 && j > 0) sumv[i][j] -= sumv[i-1][j-1];
		
		if (i > 0) sumh[i][j] += sumh[i-1][j];
		if (j > 0) sumh[i][j] += sumh[i][j-1] + (a[i][j] == '.' && a[i][j-1] == '.');
		if (i > 0 && j > 0) sumh[i][j] -= sumh[i-1][j-1];
	}
	
	ll q; cin >> q;
	while (q--) {
		ll i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		i1--, j1--, i2--, j2--;
		ll res = sumh[i2][j2] + sumv[i2][j2];
		res -= sumh[i2][j1];
		if (i1 > 0) res -= sumh[i1-1][j2] - sumh[i1-1][j1];
		res -= sumv[i1][j2];
		if (j1 > 0) res -= sumv[i2][j1-1] - sumv[i1][j1-1];
		cout << res << endl;
	}





}