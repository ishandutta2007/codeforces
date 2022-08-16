#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k, p;
	cin >> n >> m >> k >> p;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

	vector<long long> pref(k + 1);

	priority_queue<long long> pq;
	for (int j = 0; j < m; j++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i][j];
		}
		pq.push(sum);
	}

	for (int i = 1; i <= k; i++) {
		long long x = pq.top(); pq.pop();
		pref[i] = pref[i - 1] + x;
		pq.push(x - p * n);
	}

	pq = priority_queue<long long>();
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += a[i][j];
		}
		pq.push(sum);
	}

	long long ans = pref[k], cur = 0;

	for (int i = 1; i <= k; i++) {
		long long x = pq.top(); pq.pop();
		cur += x;
		pq.push(x - p * m);
		ans = max(ans, cur + pref[k - i] - (long long)(k - i) * i * p);
	}
	cout << ans << '\n';
	return 0;
}