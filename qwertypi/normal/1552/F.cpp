#include <bits/stdc++.h>
 
#define inf (1LL << 60)
#define mod 998244353
#define MAXN 500013 
#define int long long
using namespace std;
 
 
pair<int, int> p[MAXN];
bool visited[MAXN];
 
pair<int, int> bl[MAXN][30];
 
int X[200001], Y[200001], S[200001];
int dp[200001];
int s[200001];
void sub(){
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int x, y, s;
		cin >> x >> y >> s;
		X[i] = x, Y[i] = y, S[i] = s;
	}
	X[n + 1] = X[n] + 1;
	
	for(int i = 1; i <= n; i++){
		int idx = lower_bound(X, X + n + 2, Y[i]) - X; 
		dp[i] = ((X[i] - Y[i] + s[i - 1] - s[idx - 1]) % mod + mod) % mod;
		s[i] = (s[i - 1] + dp[i]) % mod;
	}
 
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += X[i] - X[i - 1];
		if(S[i]){
			ans += dp[i] % mod;
			ans %= mod;
		} 
	}
	ans++;
	ans %= mod;
	cout << ans << endl;
	
}
 
int32_t main(){
	int t = 1;
	while(t--) sub();
}