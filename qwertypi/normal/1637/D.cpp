#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
#define o 10000
using namespace std;

int A[101], B[101], D[101];
int ans = 0;
int dp[101][20001];
void solve(){
	ans = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	for(int i = 0; i < n; i++){
		D[i] = A[i] - B[i];
	}
	for(int i = 0; i < n; i++){
		ans += (n - 2) * A[i] * A[i] + (n - 2) * B[i] * B[i];
	}
	int s = accumulate(A, A + n, 0) + accumulate(B, B + n, 0);
	dp[0][o] = 1;
	for(int i = 0; i < n; i++){
		fill(dp[i + 1] + 0, dp[i + 1] + o * 2 + 1, 0);
	}
	for(int i = 0; i < n; i++){
		int d = abs(D[i]);
		for(int j = 0; j <= o * 2 - d; j++){
			dp[i + 1][j] |= dp[i][j + d];
		}
		for(int j = d; j <= o * 2; j++){
			dp[i + 1][j] |= dp[i][j - d];
		}
	}
	int min_d = inf;
	for(int i = 0; i <= o * 2; i++){
		if(dp[n][i]){
			min_d = min(min_d, abs(o - i));
		}
	}
	s = abs(s);
	ans += (s - min_d) * (s - min_d) / 4;
	ans += (s + min_d) * (s + min_d) / 4;
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}