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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll N = 710;
bool can[N][N];
ll dpleft[N][N], dpright[N][N];

bool rec_left(ll, ll), rec_right(ll, ll);

bool rec_left(ll i, ll j) {
	ll &res = dpleft[i][j];
	if (res != -1) return res;
	
	if (i == j) return 1;
	if (i+1 == j) return 1;

	res = 0;
	FOR(k,i+1,j) res = res || (can[i][k] && rec_right(i+1,k+1) && rec_left(k,j));
	return res;
}

bool rec_right(ll i, ll j) {
	ll &res = dpright[i][j];
	if (res != -1) return res;
	
	if (i == j) return 1;
	if (i+1 == j) return 1;

	res = 0;
	FOR(k,i,j-1) res = res || (can[k][j-1] && rec_right(i,k+1) && rec_left(k,j-1));
	return res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dpleft,-1,sizeof dpleft);
	memset(dpright,-1,sizeof dpright);

	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	FOR(i,0,n) FOR(j,i+1,n) can[i][j] = __gcd(a[i],a[j]) > 1;
	
	bool res = 0;
	FOR(i,0,n) res = res || (rec_right(0,i+1) && rec_left(i,n));
	cout << (res ? "Yes" : "No") << endl;	
}