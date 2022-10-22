#include <bits/stdc++.h>
using namespace std;

int N, B, D[5005], C[5005], sze[5005];
int dp[5005][5005][2];
vector<int> child[5005];

int dfs(int x) {
	int ans = 1;
	for (int i = 0; i < child[x].size(); i++) ans += dfs(child[x][i]);
	return sze[x] = ans;
}

int f(int node, int want, int discount) {
	if (dp[node][want][discount] != -1) return dp[node][want][discount];
	if (want > sze[node]) return -1000000000;
	if (!discount) {
		int *dp2[child[node].size() + 1];
		int cur = 1;
		dp2[0] = new int[2];
		dp2[0][0] = B;
		dp2[0][1] = max(0, B - C[node]);
		int bk = sze[node];
		for (int i = 1; i <= child[node].size(); i++) {
			cur += sze[child[node][i - 1]];
			dp2[i] = new int[cur + 1];
			for (int j = 0; j <= min(cur, sze[node]); j++) {
				dp2[i][j] = 0;
				for (int k = max(0, j - (cur - sze[child[node][i - 1]])); k <= min(j, sze[child[node][i - 1]]); k++) {
					dp2[i][j] = max(dp2[i - 1][j - k] - B + f(child[node][i - 1], k, 0), dp2[i][j]);
				}
			}
			bk -= sze[child[node][i - 1]];
		}
		for (int i = 0; i <= sze[node]; i++) dp[node][i][discount] = dp2[child[node].size()][i];
		return dp[node][want][discount] = dp2[child[node].size()][want];
	} else {
		int *dp2[child[node].size() + 1];
		int cur = 1, bk = sze[node];
		//memset(dp2, 0, sizeof(dp2));
		dp2[0] = new int[2];
		dp2[0][0] = 0;
		dp2[0][1] = max(0, B - C[node] + D[node]);
		for (int i = 1; i <= child[node].size(); i++) {
			cur += sze[child[node][i - 1]];
			dp2[i] = new int[cur + 1];
			//memset(dp2+i, 0, sizeof(dp2+i));
			for (int j = 0; j <= min(cur, sze[node]); j++) {
				dp2[i][j] = 0;
				for (int k = max(0, j - (cur - sze[child[node][i - 1]])); k <= min(j, sze[child[node][i - 1]]); k++) {
					dp2[i][j] = max(dp2[i - 1][j - k] - (B - max(f(child[node][i - 1], k, 0), f(child[node][i - 1], k, 1))), dp2[i][j]);
				}
			}
			bk -= sze[child[node][i - 1]];
		}
		for (int i = 0; i <= sze[node]; i++) dp[node][i][discount] = dp2[child[node].size()][i];
		return dp[node][want][discount] = dp2[child[node].size()][want];
	}
}

int main() {
	scanf("%d%d", &N, &B);
	B++;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &C[i], &D[i]);
		int x;
		if (i != 0) {
			scanf("%d", &x);
			x--;
			child[x].push_back(i);
		}
	}
	memset(dp, -1, sizeof(dp));
	dfs(0);
	int ans = 0;
	for (int i = 0; i <= N; i++) for (int j = 0; j < 2; j++) if (f(0, i, j) >= 1) ans = i;
	printf("%d\n", ans);
}