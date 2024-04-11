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

const ll MOD = 998244353;

const ll N = 5010;
ll inv[N];

void precalc() {
	inv[1] = 1;
	FOR(n,2,N) inv[n] = -(MOD/n)*inv[MOD%n] % MOD;
}

void print_prob(ll p) {
	FOR(den,1,1000) {
		ll num = p*den % MOD;
		if (num < 0) num += MOD;
		if (num > den) continue;
		cout << num << "/" << den << " ";
		return;
	}
	cout << "??? ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	precalc();

	ll n; cin >> n;
	map<ll,ll> freq = {{0,1}};
	FOR(i,0,n) {
		ll x; cin >> x;
		freq[x]++;
	}
	
	vl val, cnt;
	for (pll p: freq) val.pb(p.xx), cnt.pb(p.yy);
	ll m = sz(val);
	
	vl dp(m);
	FOR(j,1,n+1) {
		ll sum_larger = 0;
		vl ndp(m);
		FORD(i,0,m) {
			ndp[i] = inv[j] * ((cnt[i]-1) + sum_larger) % MOD;
			sum_larger = (sum_larger + cnt[i]*dp[i]) % MOD;
		}
		dp = ndp;
		//FOR(i,0,m) print_prob(dp[i]);
		//cerr << endl;
	}
	
	ll res = dp[0];
	if (res < 0) res += MOD;
	cout << res << endl;
}