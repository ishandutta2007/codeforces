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

const ll N = 55;
ll n, r, f[N], s[N];
double p[N];

double res;
double dp[N][5050];
double rec(ll i, ll j) {
	if (j < 0) return res;
	if (i == n) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	
	double ans = res;
	ans = min(ans, p[i] * (f[i] + rec(i+1,j-f[i])) + (1-p[i]) * (s[i] + rec(i+1,j-s[i])));
	return dp[i][j] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> r;
	FOR(i,0,n) cin >> f[i] >> s[i] >> p[i], p[i] /= 100;
	
	double resmin = 0, resmax = 1e20;
	FOR(k,0,100) {
		res = (resmin+resmax)/2;
		FOR(i,0,n+1) FOR(j,0,r+1) dp[i][j] = -1;
		if (rec(0,r) >= res) resmin = res; else resmax = res;
	}
	cout << fixed << setprecision(20) << resmin << endl;
}