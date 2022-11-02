#include <bits/stdc++.h>

using namespace std;

int dp[100001];
int r, n;
int t[100001], x[100001], y[100001];
void sub(){
	cin >> r >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
	}
	x[0] = 1, y[0] = 1;
	dp[0] = 0;
	
	int ans = 0;
	fill(dp + 1, dp + n + 1, -(1LL << 30));
	for(int i = 0; i < n; i++){
		for(int j = max(0, i - 2000); j <= i; j++){
			if(t[i + 1] - t[j] >= abs(x[i + 1] - x[j]) + abs(y[i + 1] - y[j])){
				dp[i + 1] = max(dp[i + 1], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i + 1]);
	}
	cout << ans << endl;
}

int32_t main(){
	int t = 1;
	while(t--){
		sub();
	}
}