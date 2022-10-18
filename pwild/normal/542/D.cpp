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

const ll maxN = 1000010;

unordered_map<ll,ll> dp[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vb pr(maxN,true);
	pr[1] = false;
	for (ll i = 2; i*i < maxN; i++) if (pr[i]) {
		for (ll j = i*i; j < maxN; j += i) pr[j] = false;
	}

	ll n; cin >> n;
	
	bool cur = true;
	dp[1][1] = 1;

	for (ll i = 2; i < maxN; i++) if (pr[i]) {
		bool found = false;
		for (ll q = i; q <= n; q *= i) if (n % (q+1) == 0) {
			if (!found) cur = !cur, dp[cur] = dp[!cur];
			found = true;
			for (const auto &t: dp[!cur]) {
				ll d = (q+1)*t.xx;
				if (n % d) continue;
				dp[cur][d] += t.yy;
			}
		}
	}
	cur = !cur;
	ll res = dp[!cur][n];
	for (const auto &t: dp[!cur]) {
		ll p = n/t.xx-1;
		if (p < maxN || p == 1) continue;
		bool isP = true;
		for (ll i = 2; i*i <= p; i++) if (pr[i] && p % i == 0) { isP = false; break; }
		if (isP) res += t.yy;
	}
	cout << res << endl;

}