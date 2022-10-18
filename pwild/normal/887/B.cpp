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
	
	ll n; cin >> n;
	vvl a(n,vl(6));
	FOR(i,0,n) FOR(j,0,6) cin >> a[i][j];
	
	ll P = 1;
	FOR(i,0,n) P *= 6;
	
	vb can(1000);

	sort(all(a));
	do {
		FOR(Q,0,P) {
			ll R = Q, cur = 0;
			FOR(i,0,n) {
				cur = 10*cur + a[i][R%6], R /= 6;
				can[cur] = true;
			}
		}
	} while (next_permutation(all(a)));
	
	ll res = 0;
	FOR(i,1,1000) {
		if (!can[i]) break;
		res = i;
	}
	cout << res << endl;
}