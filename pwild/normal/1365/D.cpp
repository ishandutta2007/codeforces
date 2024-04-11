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

bool solve() {
	ll m, n;
	cin >> m >> n;
	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];

	bool all_bad = true;
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == 'G') all_bad = false;
	if (all_bad) return true;

	auto ok = [&](ll i, ll j) { return i >= 0 && i < m && j >= 0 && j < n; };

	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == 'B') {
		FOR(di,-1,2) FOR(dj,-1,2) if (abs(di)+abs(dj) == 1) {
			ll ni = i+di, nj = j+dj;
			if (ok(ni,nj)) {
				if (a[ni][nj] == 'G') return false;
				if (a[ni][nj] == '.') a[ni][nj] = '#';
			}
		}
	}
	vvl reach(m, vl(n));
	reach[m-1][n-1] = 1;

	queue<pll> q;
	q.emplace(m-1,n-1);

	while (sz(q)) {
		auto [i,j] = q.front();
		q.pop();
		FOR(di,-1,2) FOR(dj,-1,2) if (abs(di)+abs(dj) == 1) {
			ll ni = i+di, nj = j+dj;
			if (ok(ni,nj) && a[ni][nj] != '#' && !reach[ni][nj]) {
				reach[ni][nj] = 1, q.emplace(ni,nj);
			}
		}
	}
	
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == 'G' && !reach[i][j]) return false;
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == 'B' && reach[i][j]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << (solve() ? "Yes" : "No") << endl;
}