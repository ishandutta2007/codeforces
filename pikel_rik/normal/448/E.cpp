#include <bits/stdc++.h>
using namespace std;

template<typename T>
std::vector<T> divisors(T n) {
	std::vector<T> divisors;
	for (int i = 1; (T) i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i != n / i) {
				divisors.push_back(n / i);
			}
		}
	}
	return divisors;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long x, k;
	cin >> x >> k;

	auto dx = divisors(x);
	sort(dx.begin(), dx.end());

	vector<vector<int>> d(dx.size());
	for (int i = 0; i < int(dx.size()); i++) {
		for (int j = 0; j < int(dx.size()); j++) {
			if (dx[i] % dx[j] == 0) {
				d[i].push_back(j);
			}
		}
	}

	int ans_ptr = 0;
	auto recurse = [&](int i, int turn, const auto &self) -> void {
		if (turn == k) {
			cout << dx[i] << ' ';
			ans_ptr += 1;
			return;
		}
		for (int j : d[i]) {
			if (dx[j] == 1) {
				cout << 1 << ' ';
				ans_ptr += 1;
			} else {
				self(j, turn + 1, self);
			}
			if (ans_ptr == 100000) break;
		}
	};

	recurse(int(dx.size()) - 1, 0, recurse);
	cout << '\n';
	return 0;
}