#include <bits/stdc++.h>

using namespace std;
int A[3500];
int dp[3500][3500];
void sub(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		dp[i][i] = A[i];
	}
	for(int d = 1; d < n; d++){
		for(int i = 0; i < n - d; i++){
			dp[i][i + d] = max(A[i], A[i + d]);
		}
	}
	k = min(k, m - 1);
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i >= 1 + k){
			break;
		}
		int res = (1 << 30);
		for(int j = 0; j <= m - 1 - k; j++){
			res = min(res, dp[i + j][i + j + n - m]);
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}