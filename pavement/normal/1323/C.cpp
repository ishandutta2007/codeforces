#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, dp[1000005], P[2000005], M[2000005], mat[2000005];
char S[1000005];
stack<int> stk;

main() {
	fill(M, M + 2000005, 1e9);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i], P[i] = (S[i] == '(' ? 1 : -1) + P[i - 1];
	for (int i = 1; i <= N; i++) {
		if (S[i] == '(') stk.push(i);
		else if (!stk.empty() && S[stk.top()] == '(') {
			mat[i] = stk.top();
			stk.pop();
		} else {
			while (!stk.empty()) stk.pop();
		}
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = M[P[i] + 1000000] + i + 1;
		if (P[i] == 0) dp[i] = min(dp[i], i);
		if (mat[i]) dp[i] = min(dp[i], dp[mat[i] - 1]);
		M[P[i] + 1000000] = min(M[P[i] + 1000000], dp[i] - i - 1);
	}
	if (dp[N] >= 1e9) cout << "-1\n";
	else cout << dp[N] << '\n';
}