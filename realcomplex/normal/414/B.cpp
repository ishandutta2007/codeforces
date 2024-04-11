#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
const int MAXK = 2005;
int n,k;
ll dp[MAXK][MAXK];
void ini(){
	for(int j = 1;j<=n;j++)
		dp[0][j] = 1;
	for(int i = 1;i<MAXK;i++)
		for(int l = 1;l<=n;l++)
			for(int b = l;b<=n;b+=l)
				dp[i][b] = (dp[i][b]+dp[i-1][l])%mod;
}

int main(){
	cin >> n >> k;
	ini();
	ll ans = 0;
	for(int j = 1;j<=n;j++)ans += dp[k-1][j];
	ans %= mod;
	cout << ans;
	return 0;
}