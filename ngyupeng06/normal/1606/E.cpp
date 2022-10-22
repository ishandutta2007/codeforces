#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, x, t, a, b, c, mod = 998244353, dp[505][505], p[505][505], ncr[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	ncr[0][0] = 1;
	ncr[1][0] = ncr[1][1] = 1;
	for (int i=2; i<505; i++){
		ncr[i][0] = ncr[i][i] = 1;
		for (int j=1; j<i; j++){
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
		}
	}
	for (int i=1; i<505; i++){
		p[i][0] = 1;
		for (int j=1; j<505; j++){
			p[i][j] = (p[i][j-1] * i)% mod;
		}
	}
	for (int i=0; i<=x; i++){
		dp[0][i] = 1;
		dp[1][i] = 0;
	}
	for (int i=2; i<=n; i++){
		for (int j=1; j<=x; j++){
			if (j < i) dp[i][j] = p[j][i];
			else {
				for (int k=0; k<=i; k++){
					dp[i][j] += (((ncr[i][k] * p[i-1][k]) % mod) * dp[i-k][j-i+1] ) % mod;
					dp[i][j] %= mod;
				}
			}
		}
	}
	cout << dp[n][x];
}