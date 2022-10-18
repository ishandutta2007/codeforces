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

ll m, n;

void align(vector<string> &a, vector<pll> &p, ll i, ll j, char dir) {
	if (a[i][j] == dir) return;
	if (dir == 'L') {
		align(a,p,i,j+1,'U');
		a[i][j] = a[i+1][j] = 'L';
		a[i][j+1] = a[i+1][j+1] = 'R';
	} else {
		align(a,p,i+1,j,'L');
		a[i][j] = a[i][j+1] = 'U';
		a[i+1][j] = a[i+1][j+1] = 'D';
	}
	p.eb(i+1,j+1);
}

vector<pll> go() {
	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];
	
	vector<pll> p;
	FOR(i,0,m) FOR(j,0,n) {
		if (a[i][j] == 'R' || a[i][j] == 'D') continue;
		align(a,p,i,j,m%2 ? 'L' : 'U');
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n;
	auto p = go(), q = go();
	reverse(all(q));
	cout << sz(p) + sz(q) << "\n";
	for (const auto &a: p) cout << a.xx << " " << a.yy << "\n";
	for (const auto &a: q) cout << a.xx << " " << a.yy << "\n";
}