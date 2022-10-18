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

const ll maxN = 1010;
const ll di[] = {0,-1,-1,-1,0,1,1,1,0}, dj[] = {1,1,0,-1,-1,-1,0,1};

ll n;
ll a[maxN][maxN];

ll dp[8][maxN][maxN];
ll maxlen(ll dir, ll i, ll j) {
	if (i < 0 || i >= n || j < 0 || j >= n) return -1;
	if (a[i][j] == 0) return -1;
	if (dp[dir][i][j] != -1) return dp[dir][i][j];
	return dp[dir][i][j] = 1 + maxlen(dir, i+di[dir], j+dj[dir]);
}

double dp2[8][maxN][maxN];
double sum(ll dir, ll i, ll j) {
	if (i < 0 || i >= n || j < 0 || j >= n) return 0;
	if (dp2[dir][i][j] != -1) return dp2[dir][i][j];
	double cur = a[i][j] ? log(a[i][j]) : 0;
	return dp2[dir][i][j] = cur + sum(dir, i+di[dir], j+dj[dir]);
}

double cross(ll type, ll i, ll j) {
	if (a[i][j] == 0) return -1;
	ll len = oo;
	FOR(k,0,4) len = min(len,maxlen(2*k+type, i, j));
	double res = log(a[i][j]);
	FOR(k,0,4) {
		ll dir = 2*k+type;
		res += sum(dir, i+        di[dir], j+        dj[dir]);
		res -= sum(dir, i+(len+1)*di[dir], j+(len+1)*dj[dir]);
	}
	return res;	
}

const ll MOD = 1e9 + 7;
ll crossMod(ll type, ll i, ll j) {
	if (a[i][j] == 0) return -1;
	ll len = oo;
	FOR(k,0,4) len = min(len,maxlen(2*k+type, i, j));
	ll res = a[i][j];
	FOR(k,0,4) {
		ll dir = 2*k+type;
		for (ll ci = i+di[dir], cj = j+dj[dir];
				ci != i+(len+1)*di[dir] || cj != j+(len+1)*dj[dir];
				ci += di[dir], cj += dj[dir]) {
			res = res * a[ci][cj] % MOD;
		}
	}
	return res;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	FOR(dir,0,8) FOR(i,0,n) FOR(j,0,n) dp[dir][i][j] = -1, dp2[dir][i][j] = -1;
	
	FOR(i,0,n) FOR(j,0,n) {
		char c; cin >> c;
		a[i][j] = c-'0';
	}
	double best = -1;
	ll besttype, besti, bestj;
	FOR(type,0,2) FOR(i,0,n) FOR(j,0,n) {
		double cur = cross(type,i,j);
		if (cur > best) best = cur, besttype = type, besti = i, bestj = j;
	}
	
	if (best < 0) cout << 0 << endl;
	else cout << crossMod(besttype, besti, bestj) << endl;

}