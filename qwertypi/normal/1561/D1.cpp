#include <bits/stdc++.h>
#define int long long
using namespace std;

int g[4000001]; // f'(x)
int dp[4000001]; // f(x)
int s[4000001]; // f^(-1')(x)

int N, M;
	
void solve(){
	cin >> N >> M;
	dp[0] = 0, dp[1] = 1;
	s[0] = 0, s[1] = 1;
	int grad = 0;
	{
		int i = 1;
		for(int j = 2; j * i <= N; j++){
			g[i * j] = (g[i * j] + dp[i]) % M;
			if((i + 1) * j <= N) g[(i + 1) * j] = (g[(i + 1) * j] - dp[i]) % M;
		}
	}
	for(int i = 2; i <= N; i++){
		grad = (grad + g[i]) % M;
		dp[i] = (s[i - 1] + grad) % M;
		s[i] = (s[i - 1] + dp[i]) % M;
		for(int j = 2; j * i <= N; j++){
			g[i * j] = (g[i * j] + dp[i]) % M;
			if((i + 1) * j <= N) g[(i + 1) * j] = (g[(i + 1) * j] - dp[i]) % M;
		}
	}
	
	cout << (dp[N] % M + M) % M << endl;
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}