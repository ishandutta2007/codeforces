#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, dp[200005][2];
bool B[200005];
char C;
deque<int> D, D2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> C;
		B[i] = C - '0';
	}
	for (int i = 1; i <= N; i++) {
		while (!D.empty() && D.front() < i - K) D.pop_front();
		while (!D2.empty() && D2.front() < i - K - 1) D2.pop_front();
		for (int j = 0; j <= 1; j++) {
			if (B[i] && j) {
				if (i <= K + 1) dp[i][j] = i;
				else dp[i][j] = min(dp[D2.front()][0], dp[D2.front()][1]) + i;
			} else if (B[i]) {
				dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + i;
				if (!D.empty()) dp[i][j] = min(dp[i][j], dp[D.front()][1]);
			} else if (j) {
				dp[i][j] = LLONG_MAX;
			} else {
				dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + i;
				if (!D.empty()) dp[i][j] = min(dp[i][j], dp[D.front()][1]);
			}
		}
		while (!D.empty() && dp[D.back()][1] >= dp[i][1]) D.pop_back();
		D.push_back(i);
		while (!D2.empty() && min(dp[D2.back()][0], dp[D2.back()][1]) >= min(dp[i][0], dp[i][1])) D2.pop_back();
		D2.push_back(i);
	}
	cout << min(dp[N][0], dp[N][1]) << '\n';
}