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

ll solve() {
	ll m, n;
	cin >> m >> n;

	vvl a(m, vl(n)), b(n, vl(m));

	FOR(i,0,m) {
		string s; cin >> s;
		FOR(j,0,n) a[i][j] = b[j][i] = s[j] == '#';
	}
	
	FOR(dir,0,2) {
		FOR(i,0,m) {
			FOR(j,1,n) if (a[i][j-1] && !a[i][j]) {
				FOR(k,j+1,n) if (a[i][k]) return -1;
				break;
			}
		}
		swap(m,n);
		swap(a,b);
	}
	
	bool er = false, ec = false;
	FOR(i,0,m) if (accumulate(all(a[i]),0LL) == 0) er = true;
	FOR(j,0,n) if (accumulate(all(b[j]),0LL) == 0) ec = true;
	
	if (er != ec) return -1;
	
	ll C = 0;
	vvl comp(m, vl(n,-1));
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] && comp[i][j] == -1) {
		queue<pll> q;
		q.push({i,j});
		comp[i][j] = C;

		while (sz(q)) {
			auto [i,j] = q.front();
			q.pop();

			FOR(di,-1,2) FOR(dj,-1,2) if (abs(di) + abs(dj) == 1) {
				ll ni = i+di, nj = j+dj;
				if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
				if (!a[ni][nj] || comp[ni][nj] != -1) continue;
				comp[ni][nj] = C;
				q.push({ni,nj});
			}
		}

		C++;
	}
	
	return C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << solve() << endl;
}