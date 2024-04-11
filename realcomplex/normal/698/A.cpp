#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int dp[MAXN][3];
int main(){
	int n;
	cin >> n;
	int k;
	for(int j = 1;j<=n;j++){
		cin >> k;
		dp[j][0] = max(dp[j-1][0],max(dp[j-1][1],dp[j-1][2]));
		if(k == 1 || k == 3)
			dp[j][1] = max(dp[j-1][0],dp[j-1][2])+1;
		if(k == 2 || k == 3)
			dp[j][2] = max(dp[j-1][0],dp[j-1][1])+1;
	}
	int mx = 0;
	for(int j = 0;j<MAXN;j++)
		for(int i = 0;i<3;i++)
			mx = max(mx,dp[j][i]);
	cout << n-mx;
	return 0;
}