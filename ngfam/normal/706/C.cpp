#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, w[N];
long long dp[N][2];
string s[N], rs[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> w[i];
	}

	for(int i = 1; i <= n; ++i){
		cin >> s[i];
		rs[i] = s[i];
		reverse(rs[i].begin(), rs[i].end());
	}

	memset(dp, 60, sizeof dp);

	dp[1][0] = 0;
	dp[1][1] = w[1];
	
	for(int i = 2; i <= n; ++i){
		if(s[i] >= s[i - 1]){
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		}		
		if(s[i] >= rs[i - 1]){
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}
		if(rs[i] >= s[i - 1]){
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + w[i]);
		}
		if(rs[i] >= rs[i - 1]){
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + w[i]);
		}
	}

	long long ans = min(dp[n][1], dp[n][0]);

	if(ans == dp[0][0]) ans = -1;
	cout << ans;

	return 0;
}