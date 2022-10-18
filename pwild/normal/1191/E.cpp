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

vl brute(ll n, ll k, bool dbg = false) {
	
	vvl adj(1 << n), radj(1 << n);
	FOR(mask,1,(1 << n)-1) {
		vl &v = adj[mask];
		FOR(i,0,n-k+1) {
			ll imask = ((1 << k) - 1) << i;
			ll nmask1 = mask | imask;
			ll nmask2 = mask & ~imask;
			v.pb(nmask1), v.pb(nmask2);
		}
		sort(all(v));
		v.erase(unique(all(v)),end(v));
		for (ll nmask: v) radj[nmask].pb(mask);
	}

	vl dp(1 << n);
	dp[0] = dp[(1<<n)-1] = -1;

	vl outdeg(1 << n);
	FOR(mask,0,1 << n) outdeg[mask] = sz(adj[mask]);
	
	queue<ll> q;
	q.push(0), q.push((1<<n)-1);
	
	while (sz(q)) {
		ll mask = q.front();
		q.pop();

		if (dp[mask] == -1) {
			for (ll omask: radj[mask]) {
				assert(dp[omask] != -1);
				if (dp[omask] == 1) continue;
				dp[omask] = 1;
				q.push(omask);
			}
		} else {
			for (ll omask: radj[mask]) {
				assert(dp[omask] != -1);
				if (dp[omask] == 1) continue;
				if (--outdeg[omask] == 0) {
					dp[omask] = -1;
					q.push(omask);
				}
			}
		}
	}
	
	if (dbg) {
		FOR(mask,0,1 << n) if (dp[mask] == -1) {
			FORD(i,0,n) cout << bool(mask & (1 << i));
			cout << " " << dp[mask] << endl;
		}
	}
	return dp;
}

ll solve_naive(ll n, ll k, string s) {
	vl dp = brute(n,k);
	ll mask = 0;
	FOR(i,0,n) if (s[i] == '1') mask |= 1 << i;
	return dp[mask];
}

ll solve(ll n, ll k, string s) {
	vl pmin(2,oo), pmax(2,-oo);
	FOR(i,0,n) {
		ll k = s[i]-'0';
		pmin[k] = min(pmin[k],i);
		pmax[k] = max(pmax[k],i);
	}
	
	if (pmin[0] == oo || pmin[1] == oo) return -1;
	
	FOR(i,0,2) if (pmax[i]-pmin[i]+1 <= k) return 1;
	
	assert(k < n-1);

	if (k >= n/2) {
		ll r = n-k-1;
		char c = s[0];
		bool ok = true;
		FOR(i,0,r) if (s[i] != c) ok = false;
		FOR(i,n-r,n) if (s[i] == c) ok = false;
		if (s[r] == c) ok = false;
		if (s[n-r-1] != c) ok = false;
		
		if (ok) return -1;
	}

	return 0;	
	return solve_naive(n,k,s);
}

void test() {
	FOR(n,1,8) FOR(k,1,n+1) FOR(mask,0,1 << n) {
		if (k == 1 && mask == 0) cout << n << endl;
		string s(n,'0');
		FOR(i,0,n) if (mask & (1 << i)) s[i] = '1';
		if (solve(n,k,s) != solve_naive(n,k,s)) {
			cout << n << " " << k << " " << s << endl;
			cout << solve(n,k,s) << " " << solve_naive(n,k,s) << endl;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//test();

	ll n, k;
	cin >> n >> k;
	string s; cin >> s;

	ll res = solve(n,k,s);
	if (s == string(n,'0')) res = 1;
	if (s == string(n,'1')) res = 1;
	if (res == -1) cout << "quailty" << endl;
	if (res == 1) cout << "tokitsukaze" << endl;
	if (res == 0) cout << "once again" << endl;
}