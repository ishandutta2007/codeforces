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

void compress(vl &i2x, map<ll,ll> &x2i) {
	sort(all(i2x));
	i2x.erase(unique(all(i2x)),end(i2x));
	FOR(i,0,sz(i2x)) x2i[i2x[i]] = i;
}

struct dsu {
	ll n, c;
	vl p;

	dsu(ll n): n(n), c(n), p(n) { iota(all(p),0); }
	
	ll find(ll x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	bool unite(ll x, ll y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		
		c--;
		if (rand() & 1) swap(x,y);
		p[y] = x;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;

	vector<pll> p(n);
	FOR(i,0,n) cin >> p[i].xx >> p[i].yy;
	
	vl i2x, j2y;
	for (auto [x,y]: p) i2x.pb(x), j2y.pb(y);
	
	/*
	map<ll,vl> x2y, y2x;
	for (auto [x,y]: p) x2y[x].pb(y), y2x[y].pb(x);

	for (auto [x,ys]: x2y) {
		sort(all(ys));
		FOR(t,0,sz(ys)-1) j2y.pb((ys[t]+ys[t+1])/2);
	}
	for (auto [y,xs]: y2x) {
		sort(all(xs));
		FOR(t,0,sz(xs)-1) i2x.pb((xs[t]+xs[t+1])/2);
	}
	*/

	map<ll,ll> x2i, y2j;
	compress(i2x,x2i), compress(j2y,y2j);

	ll nx = sz(i2x), ny = sz(j2y);
	dsu Dl(nx+ny);

	vector<vector<pll>> i2j(nx), j2i(ny);
	vector<pll> q;
	FOR(k,0,n) {
		auto [x,y] = p[k];
		ll i = x2i[x], j = y2j[y];
		Dl.unite(i, nx+j);

		i2j[i].eb(j,k);
		j2i[j].eb(i,k);
		q.eb(i,j);
	}
	
	if (Dl.c >= 3) {
		cout << -1 << endl;
		return 0;
	}

	for (auto &row: i2j) sort(all(row));
	for (auto &row: j2i) sort(all(row));

	vvl U(nx, vl(ny, -1)), D(nx, vl(ny, -1));
	vvl L(nx, vl(ny, -1)), R(nx, vl(ny, -1));
	FOR(k,0,n) {
		auto [i,j] = q[k];
		U[i][j] = D[i][j] = L[i][j] = R[i][j] = k;
	}
	FOR(i,0,nx) {
		FOR(j,1,ny) if (L[i][j] == -1) L[i][j] = L[i][j-1];
		FORD(j,0,ny-1) if (R[i][j] == -1) R[i][j] = R[i][j+1];
	}
	FOR(j,0,ny) {
		FOR(i,1,nx) if (U[i][j] == -1) U[i][j] = U[i-1][j];
		FORD(i,0,nx-1) if (D[i][j] == -1) D[i][j] = D[i+1][j];
	}

	ll lo = 0, hi = INT_MAX;
	while (hi-lo > 1) {
		ll r = (lo+hi)/2;
		
		dsu Dp(n);
		FOR(i,0,nx) {
			auto &v = i2j[i];
			FOR(t,0,sz(v)-1) {
				auto [j1,k1] = v[t];
				auto [j2,k2] = v[t+1];
				if (j2y[j2]-j2y[j1] <= r) Dp.unite(k1,k2);
			}	
		}
		FOR(j,0,ny) {
			auto &v = j2i[j];
			FOR(t,0,sz(v)-1) {
				auto [i1,k1] = v[t];
				auto [i2,k2] = v[t+1];
				if (i2x[i2]-i2x[i1] <= r) Dp.unite(k1,k2);
			}
		}
	
		bool ok = Dp.c == 1;

		FOR(i,0,nx) if (!ok) FOR(j,0,ny) if (!ok) {
			if (Dl.c == 2 && Dl.find(i) == Dl.find(nx+j)) continue;
			if (U[i][j] == D[i][j]) continue;
			
			vl comps;

			if (U[i][j] != -1) {
				ll pi = q[U[i][j]].xx;
				if (i2x[i]-i2x[pi] <= r) comps.pb(Dp.find(U[i][j]));
			}

			if (D[i][j] != -1) {
				ll ni = q[D[i][j]].xx;
				if (i2x[ni]-i2x[i] <= r) comps.pb(Dp.find(D[i][j]));
			}

			if (L[i][j] != -1) {
				ll pj = q[L[i][j]].yy;
				if (j2y[j]-j2y[pj] <= r) comps.pb(Dp.find(L[i][j]));
			}

			if (R[i][j] != -1) {
				ll nj = q[R[i][j]].yy;
				if (j2y[nj]-j2y[j] <= r) comps.pb(Dp.find(R[i][j]));
			}
			
			sort(all(comps));
			if (unique(all(comps)) - begin(comps) == Dp.c) ok = true;
		}
		
		FOR(i,0,nx-1) if (!ok) FOR(j,0,ny) if (!ok) {
			if (Dl.c == 2) continue;
			
			vl comps;
			
			if (U[i][j] != -1 && D[i+1][j] != -1) {
				ll pi = q[U[i][j]].xx;
				ll ni = q[D[i+1][j]].xx;
				if (i2x[ni]-i2x[pi] <= 2*r) comps.pb(Dp.find(U[i][j]));
				if (i2x[ni]-i2x[pi] <= 2*r) comps.pb(Dp.find(D[i+1][j]));
			}
			
			sort(all(comps));
			if (unique(all(comps)) - begin(comps) == Dp.c) ok = true;
		}
		
		FOR(i,0,nx) if (!ok) FOR(j,0,ny-1) if (!ok) {
			if (Dl.c == 2) continue;
			
			vl comps;
			
			if (L[i][j] != -1 && R[i][j+1] != -1) {
				ll pj = q[L[i][j]].yy;
				ll nj = q[R[i][j+1]].yy;
				if (j2y[nj]-j2y[pj] <= 2*r) comps.pb(Dp.find(L[i][j]));
				if (j2y[nj]-j2y[pj] <= 2*r) comps.pb(Dp.find(R[i][j+1]));
			}
			
			sort(all(comps));
			if (unique(all(comps)) - begin(comps) == Dp.c) ok = true;
		}
		(ok ? hi : lo) = r;
	}
	cout << hi << endl;
}