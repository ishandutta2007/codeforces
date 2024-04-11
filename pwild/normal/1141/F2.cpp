#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	map<ll,ll> dp;
	vector<vector<pll>> insertions(n+1);
	
	FOR(i,0,n+1) {
		for (pll p: insertions[i]) dp[p.xx] = max(dp[p.xx],p.yy);
		
		ll sum = 0;
		FOR(j,i,n) {
			sum += a[j];

			ll cur = 1;
			if (dp.count(sum)) cur += dp[sum];
			insertions[j+1].eb(sum,cur);			
		}
	}
	
	ll best = -1, cnt = 0;
	for (pll p: dp) if (p.yy > cnt) tie(best,cnt) = p;
	
	cout << cnt << endl;
	
	ll jmin = 0;
	FOR(i,0,n) {
		ll sum = 0;
		FORD(j,jmin,i+1) {
			sum += a[j];

			if (sum == best) {
				cout << j+1 << " " << i+1 << endl;
				jmin = i+1;
				break;
			}
		}
	}

}