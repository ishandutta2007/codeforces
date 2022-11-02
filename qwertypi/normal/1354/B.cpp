#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
int dp[200001][3];
void sub(){
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < 3; i++){
		dp[n][i] = (1 << 30);
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			if(s[i] == '1' + j){
				dp[i][j] = i;
			}else{
				dp[i][j] = dp[i + 1][j];
			}
		}
	}
	int ans = (1 << 30);
	for(int i = 0; i < n; i++){
		ans = min(max(max(dp[i][0], dp[i][1]), dp[i][2]) - i + 1, ans);
	}
	if(ans > n){
		cout << 0 << endl;
	}else{
		cout << ans << endl;
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}