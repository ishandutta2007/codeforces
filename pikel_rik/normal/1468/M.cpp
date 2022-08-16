#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> k(n);
		vector<vector<int>> a(n);

		vector<int> temp;
		for (int i = 0; i < n; i++) {
			cin >> k[i], a[i].resize(k[i]);
			for (int j = 0; j < k[i]; j++) {
				cin >> a[i][j];
				temp.push_back(a[i][j]);
			}
		}

		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		int sz = (int) temp.size();

		for (int i = 0; i < n; i++) {
			sort(a[i].begin(), a[i].end());
			for (int j = 0; j < k[i]; j++) {
				a[i][j] = lower_bound(temp.begin(), temp.end(), a[i][j]) - temp.begin();
			}
		}

		int sum_k = accumulate(k.begin(), k.end(), 0);

		vector<bool> marked(sz);
		pair<int, int> ans(-1, -1);

		for (int i = 0; i < n && ans.first == -1; i++) {
			if ((long long)k[i] * k[i] >= sum_k) {
				for (int j = 0; j < k[i]; j++) {
					marked[a[i][j]] = true;
				}
				for (int ii = 0; ii < n && ans.first == -1; ii++) {
					if (i == ii) {
						continue;
					}
					int match = 0;
					for (int j = 0; j < k[ii]; j++) {
						match += marked[a[ii][j]];
					}
					if (match >= 2) {
						ans = make_pair(i, ii);
					}
				}
				for (int j = 0; j < k[i]; j++) {
					marked[a[i][j]] = false;
				}
			}
		}

		if (ans.first != -1) {
			cout << ans.first + 1 << ' ';
			cout << ans.second + 1 << '\n';
			continue;
		}

		vector<int> l(sz);
		vector<vector<int>> v(sz);

		for (int i = 0; i < n; i++) {
			if ((long long)k[i] * k[i] >= sum_k) {
				continue;
			}
			for (int j = 0; j < k[i]; j++) {
				v[a[i][j]].push_back(i), l[a[i][j]] += 1;
			}
		}

		marked.resize(n);
		for (int i = 0; i < sz && ans.first == -1; i++) {
			if ((long long)l[i] * l[i] >= sum_k) {
				for (int j = 0; j < l[i]; j++) {
					marked[v[i][j]] = true;
				}
				for (int ii = 0; ii < sz && ans.first == -1; ii++) {
					if (i == ii) {
						continue;
					}
					int match1 = -1, match2 = -1;
					for (int j = 0; j < l[ii]; j++) {
						if (marked[v[ii][j]]) {
							match1 = match2;
							match2 = v[ii][j];
						}
					}
					if (match1 != -1 && match2 != -1) {
						ans = make_pair(match1, match2);
					}
				}
				for (int j = 0; j < l[i]; j++) {
					marked[v[i][j]] = false;
				}
			}
		}

		if (ans.first != -1) {
			cout << ans.first + 1 << ' ';
			cout << ans.second + 1 << '\n';
			continue;
		}

		vector<int> visited(sz, -1);
		for (int i = 0; i < sz && ans.first == -1; i++) {
			for (int j = 0; j < l[i] && ans.first == -1; j++) {
				for (int jj = 0; jj < k[v[i][j]]; jj++) {
					int x = a[v[i][j]][jj];
					if (x == i) {
						continue;
					}
					if (visited[x] != -1) {
						ans = make_pair(visited[x], v[i][j]);
						break;
					} else {
						visited[x] = v[i][j];
					}
				}
			}
			for (int j = 0; j < l[i]; j++) {
				for (int jj = 0; jj < k[v[i][j]]; jj++) {
					visited[a[v[i][j]][jj]] = -1;
				}
			}
		}

		if (ans.first == -1) {
			cout << "-1\n";
		} else {
			cout << ans.first + 1 << ' ';
			cout << ans.second + 1 << '\n';
		}
	}
	return 0;
}