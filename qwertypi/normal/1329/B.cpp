#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int ch[30];
int dp[31];
void sub(){
	int d, m;
	cin >> d >> m;
	for(int i = 0; i < 30; i++){
		// [(1 << i) ~ (1 << i + 1)) & [1 ~ d]
		int l = max(1LL << i, 1LL);
		int r = min((1LL << i + 1) - 1, d);
		ch[i] = max(0LL, r - l + 1);
	}
	for(int i = 0; i < 30; i++){
		dp[i] = ch[i];
		for(int j = 0; j < i; j++){
			dp[i] = (dp[i] + ch[i] * dp[j]) % m;
		}
	}
	int ans = 0;
	for(int i = 0; i < 30; i++){
		ans = (ans + dp[i]) % m;
	}
	cout << ans << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}