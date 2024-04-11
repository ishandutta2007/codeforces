#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

	int best = 0, best_moves = 0;
	for (int j = 0; j < m; j++) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += a[i][j];
		}

		int cur_best = sum, cur_best_moves = 0, cur_moves = 0;
		for (int i = 1; i + k <= n; i++) {
			cur_moves += a[i - 1][j];
			sum -= a[i - 1][j];
			sum += a[i + k - 1][j];
			if (sum > cur_best) {
				cur_best = sum;
				cur_best_moves = cur_moves;
			} else if (sum == cur_best) {
				cur_best_moves = min(cur_best_moves, cur_moves);
			}
		}
		best += cur_best;
		best_moves += cur_best_moves;
	}
	cout << best << ' ' << best_moves << '\n';
	return 0;
}