#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> lvl(n + 1);
	vector<int> p(n + 1, -1);
	queue<int> q;
	q.push(0), p[0] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i <= k; i++) {
			if (x >= k - i && n - x >= i && x - k + i + i <= n && p[x - k + i + i] == -1) {
				lvl[x - k + i + i] = 1 + lvl[x];
				p[x - k + i + i] = x;
				q.push(x - k + i + i);
			}
		}
	}

	if (p[n] == -1) {
		cout << "-1\n";
		return 0;
	}

	int ans = 0;

	vector<int> ind(n), other;
	iota(ind.begin(), ind.end(), 1);

	for (int i = n; i != 0; i = p[i]) {
		int x = (i - p[i] + k) / 2;

//		cout << i << '\n';
//		for (auto &x : ind) cout << x << ' '; cout << '\n';
//		for (auto &x : other) cout << x << ' '; cout << '\n';

		cout << "? ";
		for (int j = 0; j < x; j++) {
			cout << ind.back() << ' ';
			other.insert(other.begin(), ind.back());
			ind.pop_back();
		}

		for (int j = 0; j < k - x; j++) {
			cout << other.back() << ' ';
			ind.push_back(other.back());
			other.pop_back();
		}
		cout << endl;
		int xor_sum;
		cin >> xor_sum;
		ans ^= xor_sum;
	}
	cout << "! " << ans << endl;
	return 0;
}