#include <bits/stdc++.h>
using namespace std;

int R, N;
pair< int, pair<int, int> > P[100005];
long long dp[100005];

int main() {
	scanf("%d%d", &R, &N);
	P[0] = make_pair(0, make_pair(1, 1));
	for (int i = 0; i < N; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		P[i + 1] = make_pair(x, make_pair(y, z));
	}
	memset(dp, -63, sizeof(dp));
	dp[0] = 0;
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j >= max(i - 4 * R, 0); j--) {
			int dis = abs(P[i].second.first - P[j].second.first) + abs(P[i].second.second - P[j].second.second);
			int difftime = P[i].first - P[j].first;
			if (dis <= difftime) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
}