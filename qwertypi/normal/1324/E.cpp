#include <bits/stdc++.h>
 
using namespace std;
 
int A[2001];
int dp[2001][2001];
 
int n, h, l, r;
int reg(int x){
	while(x < 0) x += h;
	while(x >= h) x -= h;
	return x;
}
 
int main(){
	cin >> n >> h >> l >> r;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < h; j++){
			dp[i][j] = -(1 << 30);
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < h; j++){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][reg(j - A[i])] + (l <= j && j <= r));
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][reg(j - A[i] + 1)] + (l <= j && j <= r));
		}
	}
	/*
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < h; j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/
	int ans = 0;
	for(int i = 0; i < h; i++){
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl; 
}