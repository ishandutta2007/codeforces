#include <bits/stdc++.h>
using namespace std;

string S;
bool dp[1005][6];

int main() {
	cin >> S;
	dp[0][0] = 1;
	for (int i = 1; i <= S.length(); i++) {
		for (int j = 0; j <= 5; j++) {
			dp[i][j] = dp[i - 1][j];
			if (S[i - 1] == 'h' && j == 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			if (S[i - 1] == 'e' && j == 2) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			if (S[i - 1] == 'i' && (j == 3 || j == 5)) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			if (S[i - 1] == 'd' && j == 4) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
		}
	}
	if (dp[S.length()][5]) printf("YES\n");
	else printf("NO\n");
}