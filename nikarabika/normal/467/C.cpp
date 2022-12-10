#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 5e3 + 10;
ll dp[maxn][maxn];
ll s[maxn], a[maxn];
int n, m, k;

ll DP(int x, int y){
	if(x < -1)
		return -1;
	if(x == -1)
		return (y == 0) ? 0 : -1;
	if(dp[x][y] != -2)
		return dp[x][y];
	if(m * y - 1 > x)
		return -1;
	if(y == 0){
		dp[x][y] = 0;
		return 0;
	}
	dp[x][y] = DP(x - 1, y);
	ll t = DP(x - m, y - 1);
	if(t != -1)
		dp[x][y] = max(dp[x][y], t + s[x]);
	return dp[x][y];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++)
			dp[i][j] = -2;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	s[0] = a[0];
	for(int i = 1; i < m; i++)
		s[i] = s[i - 1] + a[i];
	for(int i = m; i < n; i++)
		s[i] = s[i - 1] - a[i - m] + a[i];
	cout << DP(n - 1, k) << endl;
	return 0;
}