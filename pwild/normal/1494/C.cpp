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

ll go(vl a, vl b) {
	ll m = sz(a), n = sz(b);
	if (n == 0) return 0;

	vl cnt(n);
	{
		ll i = 0;
		FOR(j,0,n) {
			while (i < m && a[i] <= b[j]) i++;
			cnt[j] = i;
		}
	}
	
	vl dp(n);
	FOR(i,0,n) {
		ll j = upper_bound(all(b), b[i]-cnt[i]) - begin(b);
		dp[i] = i-j+1;
	}

	ll res = 0, already = 0;
	FORD(i,0,n) {
		res = max(res, dp[i]+already);
		auto it = lower_bound(all(a),b[i]);
		if (it < end(a) && *it == b[i]) already++;
	}

	res = max(res, already);
	return res;
}

ll solve() {
	ll m, n;
	cin >> m >> n;
	vl a(m), b(n);
	FOR(i,0,m) cin >> a[i];
	FOR(i,0,n) cin >> b[i];

	ll res = 0;
	FOR(dir,0,2) {
		auto ita = lower_bound(all(a),0);
		auto itb = lower_bound(all(b),0);

		res += go(vl(ita,end(a)), vl(itb,end(b)));

		reverse(all(a)), reverse(all(b));
		for (ll &x: a) x = -x;
		for (ll &x: b) x = -x;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}