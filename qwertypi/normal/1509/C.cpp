#include <bits/stdc++.h>
#define int long long
using namespace std;

int s[2022];

int dp[2022][2022];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	sort(s, s + n);
	for(int i = n - 1; i >= 0; i--){
		s[i + 1] = s[i];
	}
	s[0] = -(1LL << 50);
	s[n + 1] = (1LL << 50);
	
	for(int d = 1; d < n; d++){
		for(int i = 1; i <= n + 1 - d; i++){
			dp[i][d] = min(dp[i][d - 1], dp[i + 1][d - 1]) + abs(s[i] - s[i + d]);
		}
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/
	cout << dp[1][n - 1] << endl;
}