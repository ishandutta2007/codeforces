#include <bits/stdc++.h>
using namespace std;

constexpr int N = 10000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> sum(N + 1);
	vector<int> mn(N + 1, N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			sum[j] += i;
		}
		if (sum[i] <= N) {
			mn[sum[i]] = min(mn[sum[i]], i);
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int c;
		cin >> c;

		cout << (mn[c] == N + 1 ? -1 : mn[c]) << '\n';
	}
	return 0;
}