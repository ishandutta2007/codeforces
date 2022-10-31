#include <bits/stdc++.h>

using namespace std;

const int kModular = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<int>> num_rooks_to_right(n, vector<int>(m));
	vector<vector<int>> num_rooks_to_down(n, vector<int>(m));
	for (int x = n - 1; x >= 0; x--) {
		for (int y = m - 1; y >= 0; y--) {
			num_rooks_to_right[x][y] = (a[x][y] == 'R' ? 1 : 0); 
			if (y + 1 < m) {
				num_rooks_to_right[x][y] += num_rooks_to_right[x][y + 1];
			}
			num_rooks_to_down[x][y] = (a[x][y] == 'R' ? 1 : 0);
			if (x + 1 < n) {
				num_rooks_to_down[x][y] += num_rooks_to_down[x + 1][y];
			}
		}
	}

	vector<vector<int>> num_ways_to_right(n, vector<int>(m));
	vector<vector<int>> num_ways_to_down(n, vector<int>(m));
	vector<vector<int>> sum_num_ways_to_right(n, vector<int>(m));
	vector<vector<int>> sum_num_ways_to_down(n, vector<int>(m));

	for (int x = n - 1; x >= 0; x--) {
		for (int y = m - 1; y >= 0; y--) {
			if (x == n - 1 && y == m - 1) {
				num_ways_to_right[x][y] = num_ways_to_down[x][y] = 1;
			} else {
				if (y + 1 < m) {
					num_ways_to_right[x][y] = sum_num_ways_to_down[x][y + 1];
					if (num_rooks_to_right[x][y + 1]) {
						num_ways_to_right[x][y] -= sum_num_ways_to_down[x][m - num_rooks_to_right[x][y + 1]];
					}
					num_ways_to_right[x][y] %= kModular;
				}
				if (x + 1 < n) {
					num_ways_to_down[x][y] = sum_num_ways_to_right[x + 1][y];
					if (num_rooks_to_down[x + 1][y]) {
						num_ways_to_down[x][y] -= sum_num_ways_to_right[n - num_rooks_to_down[x + 1][y]][y];
					}
					num_ways_to_down[x][y] %= kModular;
				}
			}
			sum_num_ways_to_right[x][y] = num_ways_to_right[x][y];
			if (x + 1 < n) {
				sum_num_ways_to_right[x][y] += sum_num_ways_to_right[x + 1][y];
				sum_num_ways_to_right[x][y] %= kModular;
			}
			sum_num_ways_to_down[x][y] = num_ways_to_down[x][y];
			if (y + 1 < m) {
				sum_num_ways_to_down[x][y] += sum_num_ways_to_down[x][y + 1];
				sum_num_ways_to_down[x][y] %= kModular;
			}
		}
	}
	int results = num_ways_to_right[0][0] + num_ways_to_down[0][0];
	if (n == 1 && m == 1) {
		results = 1;
	}
	printf("%d\n", (results % kModular + kModular) % kModular);
	return 0;
}