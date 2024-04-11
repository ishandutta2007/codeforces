#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 100 + 1, maxk = 10 + 1;
ll dp[2][maxn][maxn];
const ll D = 1e8;
int n1, n2, k1, k2;

ll DP(bool t, int x1, int x2){
	if(x1 < 0 or x2 < 0)
		return 0;
	if(dp[t][x1][x2] != -1)
		return dp[t][x1][x2];
	if(x1 == 0 and x2 == 0){
		dp[t][x1][x2] = 1;
		return dp[t][x1][x2];
	}
	dp[t][x1][x2] = 0;
	if(t){
		for(int i = 1; i <= k1; i++)
			dp[t][x1][x2] += DP(!t, x1 - i, x2);
		dp[t][x1][x2] %= D;
		return dp[t][x1][x2];
	}
	for(int i = 1; i <= k2; i++)
		dp[t][x1][x2] += DP(!t, x1, x2 - i);
	dp[t][x1][x2] %= D;
	return dp[t][x1][x2];
}

int main(){
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			dp[0][i][j] = (dp[1][i][j] = -1);
	cin >> n1 >> n2 >> k1 >> k2;
	cout << (DP(0, n1, n2) + DP(1, n1, n2)) % D << endl;
	return 0;
}