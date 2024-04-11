#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

bool f(vector<vector<bool>> adj, int mask_i, int mask_j) {
	vector<vector<bool>> ok(5, vector<bool>(5));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ((mask_i & (1 << i)) && (mask_j & (1 << j))) {
				ok[i][j] = true;
			}
			if (!adj[i][j]) {
				ok[i][j] = true;
			}
		}
	}

	for (int rep = 0; rep < 25; rep++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (ok[i][j]) continue;
				if (mask_i & (1 << i)) {
					int cnt = 0;
					for (int k = 0; k < 5; k++) {
						if (k != j) {
							cnt += !ok[i][k];
						}
					}
					if (!cnt) {
						ok[i][j] = true;
					}
				}
				if (mask_j & (1 << j)) {
					int cnt = 0;
					for (int k = 0; k < 5; k++) {
						if (k != i) {
							cnt += !ok[k][j];
						}
					}
					if (!cnt) {
						ok[i][j] = true;
					}
				}
			}
		}
	}

	int not_good = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			not_good += !ok[i][j];
		}
	}
	return not_good <= 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<char> chars = {'R', 'G', 'B', 'Y', 'W'};
	map<char, int> mp = {{'R', 0}, {'G', 1}, {'B', 2}, {'Y', 3}, {'W', 4}};

	vector<vector<bool>> present(5, vector<bool>(5));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		present[mp[s[0]]][s[1] - '1'] = true;
	}

	int ans = 10;
	for (int mask_i = 0; mask_i < (1 << 5); mask_i++) {
		for (int mask_j = 0; mask_j < (1 << 5); mask_j++) {
			if (f(present, mask_i, mask_j)) {
				ans = min(ans, __builtin_popcount(mask_i | (mask_j << 5)));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}