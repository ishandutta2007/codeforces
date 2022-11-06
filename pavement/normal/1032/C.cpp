#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int N, A[100005], dp[100005][10], nxt[100005][10];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= 5; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= 5; j++)
			if (A[i] > A[i - 1]) {
				for (int k = 1; k < j; k++)
					if (dp[i - 1][k])
						dp[i][j] = 1, nxt[i][j] = k;
			} else if (A[i] < A[i - 1]) {
				for (int k = j + 1; k <= 5; k++)
					if (dp[i - 1][k])
						dp[i][j] = 1, nxt[i][j] = k;
			} else for (int k = 1; k <= 5; k++)
				if (j ^ k && dp[i - 1][k])
					dp[i][j] = 1, nxt[i][j] = k;
	for (int i = 1; i <= 5; i++)
		if (dp[N][i]) {
			vector<int> V;
			for (int idx = N, cur = i; idx; cur = nxt[idx--][cur]) V.pb(cur);
			for (int i = V.size() - 1; i >= 0; i--) cout << V[i] << ' ';
			cout << '\n';
			return 0;
		}
	return cout << "-1\n", 0;
}