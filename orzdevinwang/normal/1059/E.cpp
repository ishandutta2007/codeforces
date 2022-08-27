#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int n, L, w[N], fa[N], jpfa[22][N];
int dp[N], ans[N];
ll S, jpsum[22][N];
int get(int x) {
	int gg = 0;
	ll sum = 0;
	for(int i = 20; i >= 0; i--) if(gg + (1 << i) <= L && sum + jpsum[i][x] <= S)
			sum += jpsum[i][x], gg += (1 << i), x = jpfa[i][x];
	return gg;
}
int main() {
	scanf("%d%d%lld", &n, &L, &S), jpfa[0][1] = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &w[i]), jpsum[0][i] = w[i];
		if(w[i] > S) {
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 2; i <= n; i++) scanf("%d", &fa[i]), jpfa[0][i] = fa[i];
	for(int i = 1; i <= 20; i++) 
		for(int j = 1; j <= n; j++) 
			jpfa[i][j] = jpfa[i - 1][jpfa[i - 1][j]], 
			jpsum[i][j] = jpsum[i - 1][j] + jpsum[i - 1][jpfa[i - 1][j]];
	memset(dp, -1, sizeof(dp));
	for(int i = n; i >= 1; i--) {
		if(dp[i] == -1) dp[i] = get(i) - 1, ans[i] ++;
		dp[fa[i]] = max(dp[fa[i]], dp[i] - 1), ans[fa[i]] += ans[i];
		// cout << i << " " << ans[i] << endl; 
	}
	printf("%d\n", ans[1]);
	return 0;
}