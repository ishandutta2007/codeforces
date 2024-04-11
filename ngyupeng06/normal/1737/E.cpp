#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, t;
ll mod = 1e9 + 7;
ll m = (mod + 1) / 2;
ll dp[1000005];
ll dp1[1000005];
ll ans1[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	for (int i = 1; i< 1000005; i++){
		dp[i] = dp[i-1] * m % mod;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = n; i >= 1; i--) {
			if (i == 1 && n != 1) {
				ans1[i] = 0;
				continue;
			}
			if (i == n) {
				dp1[i] = dp[i - n/2 - 1];
				ans1[i] = dp1[i];
				continue;
			}
			else {
				ll ans = dp[i - i/2];
				dp1[i] = (ans + dp1[i+1]) % mod;
				if (i <= n/2) {
					dp1[i] = (dp1[i] - (ans * dp1[2*i] % mod) + mod) % mod;
					ans = (ans - (ans * dp1[2*i] % mod) + mod) % mod;
				}
				ans1[i] = ans;
			}
		}
		for (int i =1; i<=n; i++) cout<< ans1[i] << nl;
	}
}