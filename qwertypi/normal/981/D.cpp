#include <bits/stdc++.h>

using namespace std;

int n, k;
long long A[51];
long long s[51];
long long dp[51][51];

bool test(long long mask){
	for(int i = 0; i <= 50; i++){
		for(int j = 0; j <= 50; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = mask;
	for(int c = 1; c <= k; c++){
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < i; j++){
				dp[c][i] = max(dp[c][i], mask & dp[c - 1][j] & (s[i] - s[j]));
			}
		}
	}
	return dp[k][n] == mask;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		s[i + 1] = s[i] + A[i];
	}
	long long ans = 0;
	for(int j = 60; j >= 0; j--){
		if(test(ans | (1LL << j))){
			ans |= (1LL << j);
		}
	}
	cout << ans << endl;
}