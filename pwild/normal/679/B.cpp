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

vl a = {
0,
1,
2,
3,
4,
5,
6,
7,
15,
23,
50,
114,
330,
1330,
10591,
215970,
19464802,
16542386125,
409477218238718};

ll c(ll n) { return n*n*n; }

ll cbrt(ll n) {
	ll res = pow(n,1.0/3);
	while (c(res) < n) res++;
	while (c(res) > n) res--;
	return res;
}

map<ll,pll> dp;
pll rec(ll m) {
	if (has(dp,m)) return dp[m];
	
	pll res = {0,0};
	ll iter = 0;
	for (ll n = cbrt(m); n >= 1; n--) {
		 pll cur = rec(min(m,c(n+1)) - c(n));
		 cur.xx++, cur.yy += c(n);
		 if (iter++ > 3) break;
		 //if (res.xx == 18 || c(n) < a[res.xx+1]) break;
		 res = max(res,cur);
	}
	return dp[m] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	pll best = {-oo,-oo};
	FOR(m,0,300000) {
		dp[m] = best;
		ll k = 0;
		while (k*k*k <= m) k++;
		k--;
		ll cur = m, sum = 0;
		while (cur) {
			ll cnt = cur / (k*k*k);
			//cout << cnt << " ";
			cur -= cnt*k*k*k;
			sum += cnt;
			k--;
		}
		best = max(best,{sum,m});
	}
//	cerr << "done" << endl;
	ll m; cin >> m;
	pll res = rec(m+1);
	cout << res.xx << " " << res.yy << endl;
	
}