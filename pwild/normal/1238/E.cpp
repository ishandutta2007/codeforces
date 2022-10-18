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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m, n;
	cin >> m >> n;

	string s; cin >> s;
	vvl count(n,vl(n));
	FOR(i,0,m-1) {
		ll a = s[i]-'a', b = s[i+1]-'a';
		count[a][b]++, count[b][a]++;
	}

	vl cost(1 << n);
	FOR(mask,0,1 << n) {
		FOR(i,0,n) if (mask & (1 << i)) {
			FOR(j,0,n) if (!(mask & (1 << j))) {
				cost[mask] += count[i][j];
			}
		}
	}
	
	vl dp(1 << n,oo);
	dp[0] = 0;
	FOR(mask,0,1 << n) FOR(i,0,n) if (!(mask & (1 << i))) {
		ll nmask = mask | (1 << i);
		dp[nmask] = min(dp[nmask], dp[mask] + cost[mask]);
	}
	cout << dp.back() << endl;
}