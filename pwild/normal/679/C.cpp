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

ll di[] = {-1,0,1,0}, dj[] = {0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	vector<string> a(n);
	FOR(i,0,n) cin >> a[i];

	ll C = -1;
	vvl comp(n,vl(n,-1));
	FOR(i,0,n) FOR(j,0,n) if (a[i][j] == '.' && comp[i][j] == -1) {
		queue<ll> q;
		q.push(i), q.push(j), comp[i][j] = ++C;
		while (sz(q)) {
			ll ci = q.front(); q.pop();
			ll cj = q.front(); q.pop();
			FOR(k,0,4) {
				ll ni = ci+di[k], nj = cj+dj[k];
				if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
				if (a[ni][nj] == 'X' || comp[ni][nj] != -1) continue;
				q.push(ni), q.push(nj), comp[ni][nj] = C;
			}
		}
	}
	vl compsz(++C);
	vvl h(n+1,vl(n,-1)), v(n,vl(n+1,-1));
	FOR(i,0,n) FOR(j,0,n) if (comp[i][j] != -1) {
		h[i][j] = h[i+1][j] = comp[i][j];
		v[i][j] = v[i][j+1] = comp[i][j];
		compsz[comp[i][j]]++;
	}
	
	ll res = 0;
	FOR(i0,0,n-k+1) {
		ll cur = 0;
		vl overlap(C);
		auto add = [&](ll c) {
			if (c == -1) return;
			if (!overlap[c]++) cur += compsz[c];
		};
		auto sub = [&](ll c) {
			if (c == -1) return;
			if (!--overlap[c]) cur -= compsz[c];
		};
	
		FOR(i,i0,i0+k) FOR(j,0,k) cur += a[i][j] == 'X';
		FOR(i,i0,i0+k+1) FOR(j,0,k) add(h[i][j]);
		FOR(i,i0,i0+k) FOR(j,0,k+1) add(v[i][j]);
		
		FOR(j0,0,n-k+1) {
			res = max(res,cur);
			if (j0 == n-k) break;
			FOR(i,i0,i0+k+1) sub(h[i][j0]), add(h[i][j0+k]);
			FOR(i,i0,i0+k) sub(v[i][j0]), add(v[i][j0+k+1]);
			FOR(i,i0,i0+k) cur -= a[i][j0] == 'X', cur += a[i][j0+k] == 'X';
		}
	}
	cout << res << endl;
}