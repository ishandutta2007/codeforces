#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll k, n, m, t, mod = 1e9 + 7;
ll dp[2005][2005];

ll mex(ll a, ll b){
	ll x = 1, thing = a;
	while (b){
		if (b%2){
			x = x * thing % mod;
		}
		b/=2;
		thing *= thing;
		thing %= mod;
	}
	return x;
}

ll muli(ll a){
	return mex(a, mod-2);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m >> k;
		for (int i=0; i<=n; i++){
			for (int j=0; j<=n; j++){
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[1][1] = k;
		for (int i=2; i<=n; i++){
			dp[0][i] = 0;
			dp[i][i] = i*k%mod *mex(2,i-1)%mod;
			for (int j=1; j<i; j++){
				dp[j][i] = (dp[j-1][i-1] + dp[j][i-1])%mod;
			}
		}
		cout << dp[m][n] * muli(mex(2,n-1)) % mod << "\n";
	}
}