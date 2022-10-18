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

ll brute(ll n, ll k) {
	vl cnt(n+1);
	FOR(m,1,n+1) {
		for (ll x = m; x >= 1; x = x%2 ? x-1 : x/2) cnt[x]++;
	}
	ll res = n;
	while (cnt[res] < k) res--;
	assert(res >= 0);
	return res;
}

map<ll,ll> dp;
ll solve(ll n, ll k) {
	if (n == k) return 1;
	if (n < k) return -1;
	if (n < 4) return brute(n,k);
	if (dp.count(n)) return dp[n];
	
	ll t = 1;
	while (2*t <= n) t *= 2;
	
	ll nL, nR;
	if (n < 3*t/2) {
		nR = t/2-1;
		nL = n-nR-1;
	} else {
		nL = t-1;
		nR = n-nL-1;
	}

	ll res = 2;

	ll a = solve(nL,k);
	if (a != -1) {
		FORD(i,0,63) if (a & (1LL << i)) {
			a += 1LL << i;
			break;
		}
		res = max(res, a);
	}
	
	ll b = solve(nR,k);
	if (b != -1) {
		FORD(i,0,63) if (b & (1LL << i)) {
			b += 1LL << (i+1);
			break;
		}
		res = max(res, b);
	}
	
	return dp[n] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	FOR(n,1,100) FOR(k,1,n+1) {
		if (solve(n,k) != brute(n,k)) {
			cout << n << " " << k << endl;
			return 0;
		}
		dp.clear();
	}
	
	ll n, k;
	cin >> n >> k;

	cout << solve(n,k) << endl;

}