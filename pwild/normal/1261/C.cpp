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

	vector<string> a(m+2);
	FOR(i,1,m+1) {
		string s; cin >> s;
		a[i] = "." + s + ".";
	}
	a[0] = a[m+1] = string(n+2,'.');
	m += 2, n += 2;

	vvl dist(m,vl(n,oo));
	queue<pll> q;
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == '.') {
		dist[i][j] = 0, q.push({i,j});
	}
	
	while (sz(q)) {
		auto [i,j] = q.front();
		q.pop();
		FOR(di,-1,2) FOR(dj,-1,2) if (di || dj) {
			ll ni = i+di, nj = j+dj;
			if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
			if (dist[ni][nj] < oo) continue;
			dist[ni][nj] = dist[i][j] + 1, q.push({ni,nj});
		}
	}
	
	ll tmin = 0, tmax = 1e6 + 20;
	while (tmax-tmin > 1) {
		ll t = (tmin+tmax)/2;

		vvl ndist(m,vl(n,oo));
		FOR(i,0,m) FOR(j,0,n) if (dist[i][j] > t) {
			ndist[i][j] = 0, q.push({i,j});
		}
		
		while (sz(q)) {
			auto [i,j] = q.front();
			q.pop();
			FOR(di,-1,2) FOR(dj,-1,2) if (di || dj) {
				ll ni = i+di, nj = j+dj;
				if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
				if (ndist[ni][nj] < oo) continue;
				ndist[ni][nj] = ndist[i][j] + 1, q.push({ni,nj});
			}
		}
		
		bool ok = true;
		FOR(i,0,m) FOR(j,0,n) if ((ndist[i][j] <= t) != (a[i][j] == 'X')) ok = false;
		if (ok) tmin = t; else tmax = t;
	}
/*
	ll res = oo;
	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == 'X') {
		bool cont = false;
		FOR(di,-1,2) FOR(dj,-1,2) if (di || dj) {
			ll ni = i+di, nj = j+dj;
			if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
			if (dist[ni][nj] > dist[i][j]) cont = true;
		}
		if (!cont) res = min(res, dist[i][j]-1);
	}
*/	
	
	ll res = tmin;
	cout << res << endl;
	FOR(i,1,m-1) FOR(j,1,n-1) {
		cout << ".X"[ dist[i][j] > res ];
		if (j+2 == n) cout << "\n";
	}	

}