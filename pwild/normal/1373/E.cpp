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

const ll N = 155, K = 10, M = 3e6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vl ds(M);
	FOR(n,1,M) ds[n] = n%10 + ds[n/10];

	function<ll(ll)> f = [&](ll n) {
		if (n < M) return ds[n];
		return n%10 + f(n/10);
	};

	vvl dp(N, vl(K, oo));

	FOR(k,0,10) FOR(x,0,M-k-1) {
		ll n = 0;
		FOR(j,0,k+1) n += ds[x+j];
		if (n < N) dp[n][k] = min(dp[n][k],x);
	}

	FOR(k,0,10) FOR(len,1,18) FOR(a,0,len) FOR(d,0,10) FOR(b,a+1,len) FOR(e,0,10) {
		string num(len,'9');
		num[a] = '0'+d, num[b] = '0'+e;
		ll x = stoll(num.c_str()), n = 0;
		FOR(j,0,k+1) n += f(x+j);
		if (n < N) dp[n][k] = min(dp[n][k],x);
	}

	FOR(n,0,N) FOR(k,0,K) if (dp[n][k] == oo) dp[n][k] = -1;

	ll tc; cin >> tc;
	while (tc--) {
		ll n, k;
		cin >> n >> k;
		cout << dp[n][k] << endl;
	}
}