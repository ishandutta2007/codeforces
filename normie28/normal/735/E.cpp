#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAX_N = 100 + 3, MAX_K = 20 + 3, MOD = 1000000007;
 
#define len(x) ((int)x.size())
vector<int> G[MAX_N];
int n, K, dp[MAX_N][MAX_K][MAX_K];
 
void Dp(int u, int fa = -1) {
	memset(dp[u], 0, sizeof dp[u]);
	dp[u][-1 + 1][0 + 1] = 1, dp[u][0 + 1][-1 + 1] = 1;
	
	bool f1 = false, f2 = false;
	for (int i = 0, e; i < len(G[u]); ++i) {
		int v = G[u][i];
		if (v == fa) continue;
		Dp(v, u);
	
		static int t[MAX_K][MAX_K];
		memset(t, 0, sizeof t);
		for (int a = -1; a <= K; ++a)
			for (int b = -1; b <= K; ++b) if (dp[u][a + 1][b + 1])
				for (int c = -1; c <= K; ++c)
					for (int d = -1; d <= K; ++d) if (dp[v][c + 1][d + 1]) {
						f1 = b == -1, f2 = d == -1;
						if (!f1 && c != -1 && b + c + 1 <= K) f1 = true;
						if (!f2 && a != -1 && d + a + 1 <= K) f2 = true;
						
						if (a == -1 && c == -1) e = -1;
						else if (a == -1) e = c + 1;
						else if (c == -1) e = a;
						else e = min(a, c + 1);
						if (e > K) e = -1;
 
						if (f1 && f2) (t[e + 1][-1 + 1] += (ll)dp[u][a + 1][b + 1] * dp[v][c + 1][d + 1] % MOD) %= MOD;
						else if (f1) (t[e + 1][d + 1 + 1] += (ll)dp[u][a + 1][b + 1] * dp[v][c + 1][d + 1] % MOD) %= MOD;
						else if (f2) (t[e + 1][b + 1] += (ll)dp[u][a + 1][b + 1] * dp[v][c + 1][d + 1] % MOD) %= MOD;
						else (t[e + 1][max(b, d + 1) + 1] += (ll)dp[u][a + 1][b + 1] * dp[v][c + 1][d + 1] % MOD) %= MOD;
					}
 
		memcpy(dp[u], t, sizeof t);
	}
}
 
int main() {
    cin>>n>>K;
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin>>u>>v, --u, --v;
		G[u].push_back(v), G[v].push_back(u);
	}
	
	Dp(0);
	int ans = 0;
	for (int i = 0; i <= K; ++i) (ans += dp[0][i + 1][-1 + 1]) %= MOD;
	cout<<ans;
}