#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int max_n = 200000;
	constexpr int max_k = 20;
	constexpr int max_msg = 80;

	int n;
	cin >> n;

	vector<int> m(n), k(n);
	for (int i = 0; i < n; i++) {
		cin >> m[i] >> k[i], --m[i];
	}

	long long best_num = 0, best_den = 1;
	vector<int> best_vector = {};

	for (int no_msg = 1; no_msg <= max_msg; no_msg++) {
		static vector<long long> contribution(max_n);
		fill(contribution.begin(), contribution.end(), 0);

		for (int i = 0; i < n; i++) {
			if (no_msg <= k[i]) {
				contribution[m[i]] += no_msg;
			} else {
				contribution[m[i]] += k[i];
			}
		}

		static vector<int> ind(max_n);
		iota(ind.begin(), ind.end(), 0);
		nth_element(ind.begin(), ind.begin() + no_msg, ind.end(), [&](int i, int j) {
			return contribution[i] > contribution[j];
		});

		long long now_num = 0, now_den = no_msg;
		for (int i = 0; i < no_msg; i++) {
			now_num += contribution[ind[i]];
		}

		if (now_num * best_den > now_den * best_num) {
			best_num = now_num, best_den = now_den;
			best_vector.assign(ind.begin(), ind.begin() + no_msg);
		}
	}

	cout << best_vector.size() << '\n';
	for (int i : best_vector) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
	return 0;
}