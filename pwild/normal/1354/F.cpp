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

struct matching {
	ll L, R;
	vl potL, potR, matchR, pred;

	matching(vvl cost): L(sz(cost)), R(sz(cost[0])),
	                    potL(L+1), potR(R+1), matchR(R+1,L), pred(R+1,L) {
		FOR(si,0,L) {
			ll cj = R;
			matchR[cj] = si;
			vl minR(R+1,oo);
			vb used(R+1);
			do {
				used[cj] = true;
				ll i = matchR[cj], delta = oo, bj;
				FOR(j,0,R) if (!used[j]) {
					ll cur = cost[i][j] - potL[i] - potR[j];
					if (cur < minR[j]) minR[j] = cur, pred[j] = cj;
					if (minR[j] < delta) delta = minR[j], bj = j;
				}
				FOR(j,0,R+1) {
					if (used[j]) potL[matchR[j]] += delta, potR[j] -= delta;
					else minR[j] -= delta;
				}
				cj = bj;
			} while (matchR[cj] != L);
			do {
				ll nj = pred[cj];
				matchR[cj] = matchR[nj];
				cj = nj;
			} while (cj != R);
		}
	}

	ll max_match() {
		return -potR[R];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, k;
		cin >> n >> k;
		
		vl a(n), b(n);
		FOR(i,0,n) cin >> a[i] >> b[i];

		vvl cost(n, vl(n));
		FOR(i,0,n) FOR(j,0,n) {
			if (j < k) cost[i][j] = a[i] + j*b[i];
			else cost[i][j] = (k-1)*b[i];

			cost[i][j] = -cost[i][j];
		}

		matching M(cost);
//		cerr << M.max_match() << endl;
//		FOR(j,0,n) cerr << M.matchR[j] << " " << j << " " << cost[M.matchR[j]][j] << endl;

		vl res;
		FOR(i,0,k-1) res.pb(M.matchR[i]+1);
		FOR(i,k,n) {
			ll x = M.matchR[i]+1;
			res.pb(x), res.pb(-x);
		}
		res.pb(M.matchR[k-1]+1);

		cout << sz(res) << endl;
		for (ll x: res) cout << x << " ";
		cout << endl;
	}
}