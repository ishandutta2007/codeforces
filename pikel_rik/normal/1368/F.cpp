#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n <= 3) {
		cout << 0 << endl;
		return 0;
	}

	int best = 0, best_score = 0;
	vector<int> target;

	for (int len = 1; len <= n - 2; len++) {
		vector<int> want;
		for (int i = 0, cur = 0; i < n - 1; i++) {
			if (cur + 1 <= len) {
				want.push_back(i);
				cur += 1;
			} else {
				cur = 0;
			}
		}
		if ((int) want.size() - len > best_score) {
			best = len + 1;
			best_score = (int) want.size() - len;
			target = want;
		}
	}

	vector<bool> taken(n);
	while (true) {
		vector<int> take;
		for (int i : target) {
			if (!taken[i] && take.size() < best) {
				take.push_back(i);
			}
		}

		if (take.size() < best) {
			break;
		}

		cout << best << ' ';
		for (int i : take) {
			cout << i + 1 << ' ';
			taken[i] = true;
		}
		cout << endl;

		int x;
		cin >> x, --x;

		for (int j = 0; j < best; j++) {
			taken[(x + j) % n] = false;
		}
	}
	cout << 0 << endl;
	return 0;
}