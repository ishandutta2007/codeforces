#include <bits/stdc++.h>
using namespace std;

template<typename T, int D>
struct tensor : std::vector<tensor<T, D - 1>> {
	tensor() : std::vector<tensor<T, D - 1>>() {}

	template<typename...args>
	tensor(size_t n, args...A) : std::vector<tensor<T, D - 1>>(n, tensor<T, D - 1>(A...)) {}

	tensor(const std::initializer_list<tensor<T, D - 1>> &list) : std::vector<tensor<T, D - 1>>(list) {}

	void fill(const T &val) {
		for (auto it = this->begin(); it != this->end(); it++) {
			it->fill(val);
		}
	}
};

template<typename T>
struct tensor<T, 1> : std::vector<T> {
	tensor() : std::vector<T>() {}

	tensor(size_t n, const T &val = T()) : std::vector<T>(n, val) {}

	tensor(const std::initializer_list<T> &list) : std::vector<T>(list) {}

	void fill(const T &val = T()) {
		std::fill(this->begin(), this->end(), val);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		string x;
		cin >> x;

		tensor<bool, 4> visited(n + 1, 2 * n + 1, a, b);
		tensor<pair<int, int>, 4> parent(n + 1, 2 * n + 1, a, b);

		queue<tuple<int, int, int, int>> q;
		q.emplace(0, n, 0, 0);

		visited[0][n][0][0] = true;
		parent[0][n][0][0] = make_pair(-1, -1);

		while (!q.empty()) {
			auto [i, diff, am, bm] = q.front();
			q.pop();

			if (i == n) {
				continue;
			}

			int nam = (10 * am + x[i] - '0') % a, nbm = (10 * bm + x[i] - '0') % b;
			if (!visited[i + 1][diff + 1][nam][bm]) {
				parent[i + 1][diff + 1][nam][bm] = make_pair(0, am);
				visited[i + 1][diff + 1][nam][bm] = true;
				q.emplace(i + 1, diff + 1, nam, bm);
			}
			if (!visited[i + 1][diff - 1][am][nbm]) {
				parent[i + 1][diff - 1][am][nbm] = make_pair(1, bm);
				visited[i + 1][diff - 1][am][nbm] = true;
				q.emplace(i + 1, diff - 1, am, nbm);
			}
		}

		int mn = n;
		for (int diff = -n + 1; diff < n; diff++) {
			if (visited[n][n + diff][0][0] && abs(diff) < abs(mn)) {
				mn = diff;
			}
		}

		if (mn == n) {
			cout << "-1\n";
			continue;
		}

		string ans;

		int am = 0, bm = 0;
		for (int i = n; i > 0; i--) {
			if (parent[i][n + mn][am][bm].first == 0) {
				ans += 'R';
				am = parent[i][n + mn][am][bm].second;
				mn -= 1;
			} else {
				ans += 'B';
				bm = parent[i][n + mn][am][bm].second;
				mn += 1;
			}
		}

		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}