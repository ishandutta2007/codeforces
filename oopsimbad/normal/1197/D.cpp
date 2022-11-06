#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back


///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	ll dp[10];
	F0R(i, m) dp[i] = -99999999999LL;
	dp[m-1] = 0;
	ll ans = 0;
	F0R(i, n) {
		ll a; cin >> a;
		ll ndp[10];
		F0R(j, m) ndp[j] = dp[(j+m-1)%m]+a;
		ndp[0] -= k;
		ndp[m-1] = max(ndp[m-1],0LL);
		F0R(j, m) ans = max(ans, dp[j] = ndp[j]);
		cout << endl;
	}
	cout << ans << endl;
///
	return 0;
}