#include <bits/stdc++.h>

const int INF = 1E9;

int N, K;
char map[2100][2100];
int dp[2100][2100];
char str[11000]; int p = 0;

int main () {
	scanf ("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)
		scanf (" %c", &map[i][j]);
	if (K == 0) {
		dp[1][1] = 0; str[p++] = map[1][1];
	} else {
		if (map[1][1] == 'a')
			dp[1][1] = 0, str[p++] = 'a';
		else
			dp[1][1] = 1, str[p++] = 'a';
	}
	for (int t = 2; t <= 2 * N - 1; ++t) {
		bool all_full = 1; char min_char = 127;
		int bx, by;
		if (t - 1 <= N) bx = t - 1, by = 1;
		else bx = N, by = t - 1 - N + 1;
		while (bx >= 1 && by >= 1 && bx <= N && by <= N) {
			if (dp[bx][by] < K) all_full = 0;
			--bx; ++by;
		}
		if (t <= N) bx = t, by = 1;
		else bx = N, by = t - N + 1;
		while (bx >= 1 && by >= 1 && bx <= N && by <= N) {
			if ((bx - 1 >= 1 && dp[bx - 1][by] < INF) || (by - 1 >= 1 && dp[bx][by - 1] < INF))
				min_char = std::min (map[bx][by], min_char);
//			printf ("%d %d %c\n", bx, by, map[bx][by]);
			--bx; ++by;
		}
		if (!all_full) min_char = 'a';
		if (t <= N) bx = t, by = 1;
		else bx = N, by = t - N + 1;
		while (bx >= 1 && by >= 1 && bx <= N && by <= N) {
			dp[bx][by] = INF;
			if (bx - 1 >= 1) dp[bx][by] = std::min (dp[bx][by], dp[bx - 1][by]);
			if (by - 1 >= 1) dp[bx][by] = std::min (dp[bx][by], dp[bx][by - 1]);
			if (map[bx][by] != min_char) {
				if (++dp[bx][by] > K) dp[bx][by] = INF;
			}
			--bx; ++by;
		}
		str[p++] = min_char;
	}
//	for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) printf ("%d%c", dp[i][j], "\t\n"[j == N]);
	puts (str);
}