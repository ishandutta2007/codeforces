#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> p(n);
		for (auto &x : p) cin >> x, --x;

		deque<int> answer;

		int mn = n;
		for (int i = 0; i < n; i++) {
			if (p[i] < mn) {
				answer.push_front(p[i]);
				mn = p[i];
			} else {
				answer.push_back(p[i]);
			}
		}

		for (auto &x : answer) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}