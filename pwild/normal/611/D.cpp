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

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	string a; cin >> a;
//	a = " " + a;

	vector<ll> dpsum(n+1);
	dpsum[0] = 1;

	vl rk(n+1);

	FOR(j,1,n+1) {
		auto cmp = [&](const ll &i1, const ll &i2) {
			if (a[i1] != a[i2]) return a[i1] < a[i2];
			return rk[i1+1] < rk[i2+1];
		};
		vector<ll> ndp(n+1);
		FOR(i,j,n+1) {
			if (a[i-j] == '0') continue;
			ndp[i] = dpsum[i-j];
			if (i >= 2*j && cmp(i-2*j,i-j)) ndp[i] = (ndp[i] + ndp[i-j]) % MOD;
		}
		FOR(i,0,n+1) dpsum[i] = (dpsum[i] + ndp[i]) % MOD;

		vl is(n+1-j);
		FOR(i,0,n+1-j) is[i] = i;
		sort(all(is),cmp);
		vl nrk(n+1-j);
		ll cnt = 0;
		FOR(k,0,n+1-j) {
			if (k > 0 && cmp(is[k-1],is[k])) cnt++;
			nrk[is[k]] = cnt;
		}
		rk = nrk;
	}
	
	cout << dpsum[n] << endl;






}