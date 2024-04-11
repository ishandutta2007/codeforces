#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
const int MAXN = 105;
int n,k,t;
ll dp[MAXN][2];

void calc(){
	dp[0][0] = 1;
	for(int j = 1;j<=n;j++){
		for(int i = 1;i<=k;i++){
			if(j-i<0)continue;
			dp[j][1] = (dp[j][1]+dp[j-i][1])%mod;
			if(i<t)
				dp[j][0] = (dp[j][0]+dp[j-i][0])%mod;
			else
				dp[j][1] = (dp[j][1]+dp[j-i][0])%mod;
		}
	}
}

int main(){
	cin >> n >> k >> t;
	calc();
	cout << dp[n][1];
	return 0;
}