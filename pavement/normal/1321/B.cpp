#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, B[200005], dp[200005];
map<int, int> M;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = N; i >= 1; i--) {
		dp[i] = B[i] + M[B[i] - i];
		M[B[i] - i] = max(M[B[i] - i], dp[i]);
	}
	cout << *max_element(dp + 1, dp + 1 + N) << '\n';
}