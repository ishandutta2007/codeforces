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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vl a(3), b(3);
	FOR(i,0,3) cin >> a[i] >> b[i];

	ll k2 = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];

	ll k = 0;
	while (k*k < k2) k++;
	if (k*k != k2) {
		cout << -1 << endl;
		return 0;
	}
	
	vl p = {0,1,2};
	do {
		FOR(mask,0,8) {
			FOR(i,0,3) if (mask & (1 << i)) swap(a[i],b[i]);
			
			vector<string> c(k,string(k,' '));
			
			bool ok = true;
			ll cur = 0;
			FOR(i,0,k) FOR(j,0,k) if (ok && cur < 3) {
				if (c[i][j] != ' ') continue;
				if (i + a[p[cur]] > k || j + b[p[cur]] > k) {
					ok = false;
					break;
				}
				FOR(ni,i,i + a[p[cur]]) FOR(nj,j,j + b[p[cur]]) {
					if (c[ni][nj] != ' ') ok = false;
					c[ni][nj] = 'A'+cur;
				}
				cur++;
			}
			
			if (ok) {
				cout << k << endl;
				FOR(i,0,k) cout << c[i] << endl;
				return 0;
			}


			FOR(i,0,3) if (mask & (1 << i)) swap(a[i],b[i]);
		}
	} while (next_permutation(all(p)));

	cout << -1 << endl;

}