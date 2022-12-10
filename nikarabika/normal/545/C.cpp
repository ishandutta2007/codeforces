#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 10;
LL dp[maxn][3];
LL x[maxn], h[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> h[i];
	x[0] = -2e9;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	dp[n][0] = 1;
	dp[n][1] = ((x[n - 1] >= x[n] - h[n]) ? 0 : 1);
	dp[n][2] = 0;
	for(int i = n - 1; i > 0; i--){
		dp[i][2] = max(max(dp[i + 1][0], dp[i + 1][1]), dp[i + 1][2]);
		//dp[i][0]
		if(x[i] + h[i] < x[i + 1] - h[i + 1])
			dp[i][0] = dp[i][2] + 1;
		else if(x[i] + h[i] >= x[i + 1])
			dp[i][0] = 0;
		else
			dp[i][0] = max(dp[i + 1][0], dp[i + 1][2]) + 1;
		//dp[i][1]
		if(x[i] - h[i] > x[i - 1])
			dp[i][1] = dp[i][2] + 1;
		else
			dp[i][1] = 0;
	}
	cout << max(max(dp[1][0], dp[1][1]), dp[1][2]) << endl;
	return 0;
}