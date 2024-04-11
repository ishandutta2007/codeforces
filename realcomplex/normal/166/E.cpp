#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
const int MAXN = 1e7+5;
int dp[MAXN][4];

void calc(){
	dp[0][3] = 1;
	for(int j = 1;j<=MAXN;j++){
		dp[j][0]=(0LL+dp[j-1][1]+dp[j-1][2]+dp[j-1][3])%mod;
		dp[j][1]=(0LL+dp[j-1][0]+dp[j-1][2]+dp[j-1][3])%mod;
		dp[j][2]=(0LL+dp[j-1][0]+dp[j-1][1]+dp[j-1][3])%mod;
		dp[j][3]=(0LL+dp[j-1][0]+dp[j-1][1]+dp[j-1][2])%mod;
	}
}

int main(){
	calc();
	int n;
	cin >> n;
	cout << dp[n][3];
	return 0;
}