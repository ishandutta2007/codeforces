#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 7, maxd = 1e5 + 85 - 69;
int dp[maxn][maxd * 2];
int n, k, a[maxn], b[maxn];

void DP(int x, int d){
	if(dp[x][d] != -1)
		return;
	if(x == 0){
		if(d == maxd) dp[x][d] = 0;
		else dp[x][d] = -2;
		return;
	}
	DP(x - 1, d);
	dp[x][d] = dp[x - 1][d];
	int dd = d + a[x] - b[x];
	DP(x - 1, dd);
	if(dp[x - 1][dd] >= 0)
		dp[x][d] = max(dp[x][d], dp[x - 1][dd] + a[x]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i], b[i] *= k;
	memset(dp, -1, sizeof dp);
	DP(n, maxd);
	if(dp[n][maxd] <= 0)
		cout << -1 << endl;
	else
		cout << dp[n][maxd] << endl;
	return 0;
}