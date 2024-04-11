#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	int N, K, G;
	scanf("%d %d", &N, &K);
	G = 1 << (N - 1);
	vector<vector<int>> dp(2 * G, {0, -INF, -INF, -INF});

	for (int i = 0; i < K; i++) {
		int a;
		scanf("%d", &a);
		a--;
		a = G + a / 2;
		dp[a][3] = dp[a][1];
		dp[a][1] = dp[a][2] = 1;
	}

	for (int g = G - 1; g > 0; g--)
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				dp[g][x | y] = max(dp[g][x | y], dp[2 * g][x] + dp[2 * g + 1][y] + (x | y));

	printf("%d\n", max({dp[1][1], dp[1][2], dp[1][3], -1}) + 1);
}