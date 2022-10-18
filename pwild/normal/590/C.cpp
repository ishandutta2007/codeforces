#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 1e12;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n;
	cin >> m >> n;

	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];
	
	vector<vvl> dist(3,vvl(m,vl(n,oo)));
	FOR(k,0,3) {
		queue<pll> q;
		FOR(i,0,m) FOR(j,0,n) if (a[i][j]-'1' == k) {
			dist[k][i][j] = 0;
			q.push({i,j});
		}
		while (sz(q)) {
			auto [i,j] = q.front();
			q.pop();
			FOR(di,-1,2) FOR(dj,-1,2) if (abs(di)+abs(dj) == 1) {
				ll ni = i+di, nj = j+dj;
				if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
				if (a[ni][nj] == '#' || dist[k][ni][nj] < oo) continue;
				dist[k][ni][nj] = dist[k][i][j] + 1;
				q.push({ni,nj});
			}
		}
	}
	
	vvl dc(3,vl(3,oo));
	FOR(k,0,3) FOR(i,0,m) FOR(j,0,n) {
		char c = a[i][j];
		if (!isdigit(c)) continue;
		dc[k][c-'1'] = min(dc[k][c-'1'], dist[k][i][j]);
	}

	ll res = oo;
	FOR(k,0,3) res = min(res, dc[k][(k+1)%3] + dc[k][(k+2)%3] - 2);
	
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == '.') {
		ll cur = 1;
		FOR(k,0,3) cur += dist[k][i][j] - 1;
		res = min(res, cur);
		// cerr << cur << endl;
	}

	if (res >= oo-20) res = -1;
	cout << res << endl;
}