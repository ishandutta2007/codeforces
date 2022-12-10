#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxb = 5e2 + 1;
int dp[maxb][maxb];
int n, m, b, Mod;
int a[maxb];

void DP(){
	dp[0][0] = 1;
	for(int j = 1; j <= n; j++)
		for(int i = 1; i <= m; i++)
			for(int k = a[j]; k <= b; k++)
				dp[i][k] = (dp[i][k] + dp[i - 1][k - a[j]]) % Mod;
}

/*void DP(int i, int j, int k){
	//BASE
	if(i == 0){
		if(k == 0)
			dp[i][j][k] = 1;
		else
			dp[i][j][k] = 0;
		return;
	}
	if(j == 0){
		if(i == 0 and k == 0)
			dp[i][j][k] = 1;
		else
			dp[i][j][k] = 0;
		return;
	}
	//Recurse!
	if(dp[i][j - 1][k] == -1)
		DP(i, j - 1, k);
	dp[i][j][k] = dp[i][j - 1][k];
	if(k >= a[j]){
		if(dp[i - 1][j][k - a[j]] == -1)
			DP(i - 1, j, k - a[j]);
		dp[i][j][k] += dp[i - 1][j][k - a[j]];
	}
	dp[i][j][k] %= Mod;
}*/

int main(){
	ios_base::sync_with_stdio(false);
	//memset(dp, -1, sizeof dp);
	cin >> n >> m >> b >> Mod;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	DP();
	for(int k = 0; k <= b; k++){
		ans = (ans + dp[m][k]) % Mod;
	}
	cout << ans << endl;
	return 0;
}