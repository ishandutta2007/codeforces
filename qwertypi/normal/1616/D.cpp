#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int n, A[300001], x;
int dp[300001];
int s[300001];
int _far[300001];
int st[50001][20], st2[50001][20];
int far(int idx){
	int en = idx - 1, ttl = A[idx];
	for(int j = 19; j >= 0; j--){
		if(st[en][j] + ttl >= 0){
			ttl += s[en + 1] - s[en + 1 - (1 << j)];
			en -= (1 << j);
		}
		if(en == -1) return 0;
	}
	return en + 1;
}
 
void solve(){
	cin >> n;
	_far[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	cin >> x;
	if(n == 1){
		cout << 1 << endl;
		return;
	}
	for(int i = 0; i < n; i++){
		A[i] -= x;
	}
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + A[i];
	}
	
	for(int i = 0; i < n; i++){
		st[i][0] = A[i];
	}
	
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= n; i++){
			st[i][j] = -1LL << 60;
		}
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= n - (1 << j); i++){
			st[i + (1 << j) - 1][j] = min(st[i + (1 << j) - 1][j - 1], st[i + (1 << j - 1) - 1][j - 1] + s[i + (1 << j)] - s[i + (1 << j - 1)]);
		}
	}
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 1; i < n; i++){
		int f = max(_far[i], far(i)); _far[i + 1] = f;
		// cout << "far: " << i << ' ' << f << endl;
		
		dp[i + 1] = max(dp[i - 1] + 1, dp[i]);
		dp[i + 1] = max(dp[i + 1], (f == 0 ? i + 1 : dp[f - 1] + (i - f + 1)));
	}
//	for(int i = 0; i <= n; i++){
//		cout << dp[i] << ' ';
//	}
//	cout << endl;
	cout << dp[n] << endl;
}
 
int32_t main(){
	int q;
	cin >> q;
	while(q--){
		solve();
	}
}