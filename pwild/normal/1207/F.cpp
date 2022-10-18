#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

const ll N = 500010, M = 500;
ll a[N], asum[M][M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	ll q; cin >> q;
	while (q--) {
		ll type, x, y;
		cin >> type >> x >> y;
		
		if (type == 1) {
			a[x] += y;
			FOR(z,1,M) asum[z][x%z] += y;
		} else {
			ll res = 0;
			if (x < M) res = asum[x][y];
			else for (ll z = y; z < N; z += x) res += a[z];
			cout << res << '\n';
		}	
	}
}