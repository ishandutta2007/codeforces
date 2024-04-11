#include <bits/stdc++.h>

using namespace std;

unsigned d[501], A[501];
unsigned dp[501][501]; // till i remove j
int main(){
	int n, l, k;
	cin >> n >> l >> k;
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	d[n] = l;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = (1 << 30);
		}
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k <= n - (i - j - 1); k++){
				dp[i][k + (i - j - 1)] = min(dp[i][k + (i - j - 1)], dp[j][k] + (d[i] - d[j]) * A[j]);
			}
		}
	}
	
	unsigned ans = (1 << 30);
	for(int j = 0; j <= k; j++){
		ans = min(ans, dp[n][j]);
	}
	cout << ans << endl;
}