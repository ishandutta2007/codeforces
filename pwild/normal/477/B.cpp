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

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a%b); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;

	ll m = 6*n - 1;
	cout << k*m << endl;
	
	FOR(i,0,n) {
		vl res(4);
		res[0] = 6*i + 1;
		res[1] = 6*i + 2;
		res[2] = 6*i + 3;
		res[3] = 6*i + 5;
//		FOR(i1,0,4) FOR(i2,i1+1,4) if (gcd(res[i1],res[i2]) != 1) {
//			cout << res[i1] << " " << res[i2] << endl;
//		}
		FOR(j,0,4) cout << k*res[j] << " \n"[j == 3];
	}




}