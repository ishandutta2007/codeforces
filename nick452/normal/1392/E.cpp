#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<long long>> a(n, vector<long long>(n));
	vector<vector<long long>> min_val(n, vector<long long>(n));
	vector<vector<long long>> max_val(n, vector<long long>(n));
	for (int s = 1; s <= (n - 1) * 2; ++s) {
		long long next = 0;
		for (int x = 0; x < n; x++) {
			int y = s - x;
			if (y < 0 || y >= n) {
				continue;
			}
			long long min_d = +(1LL << 60);
			long long max_d = -(1LL << 60);
			if (x - 1 >= 0) {
				min_d = min(min_d, min_val[x - 1][y]);
				max_d = max(max_d, max_val[x - 1][y]);
			}
			if (y - 1 >= 0) {
				min_d = min(min_d, min_val[x][y - 1]);
				max_d = max(max_d, max_val[x][y - 1]);
			}
			a[x][y] = next - min_d;
			min_val[x][y] = next;
			max_val[x][y] = a[x][y] + max_d;
			next = max_val[x][y] + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%lld ", a[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);
	int q;
	cin >> q;
	while (q--) {
		long long l;
		cin >> l;
		int x = n - 1;
		int y = n - 1;
		vector<pair<int, int>> path;
		while (1) {
			path.push_back(make_pair(x, y));
			if (x + y == 0) {
				break;
			}
			l -= a[x][y];
			if (y == 0 || x > 0 && l <= max_val[x - 1][y]) {
				--x;
			}
			else {
				--y;
			}
		}
		reverse(path.begin(), path.end());
		for (const auto& p : path) {
			printf("%d %d\n", p.first + 1, p.second + 1);
		}
	}
	return 0;
}