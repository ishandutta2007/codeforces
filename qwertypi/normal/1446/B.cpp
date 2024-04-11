#include <bits/stdc++.h>

#define int long long
using namespace std;

int dp[5001][5001];
int32_t main(){
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dp[i + 1][j + 1] = max(max(dp[i + 1][j], dp[i][j + 1]) - 1, 0LL);
			if(s[i] == t[j]){
				dp[i + 1][j + 1] = max(dp[i][j] + 2, dp[i + 1][j + 1]);
			}
			ans = max(ans, dp[i + 1][j + 1]); 
		}
	}

	cout << ans << endl;
}