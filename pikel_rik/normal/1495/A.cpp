#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(12);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> miners, mines;
		miners.reserve(n), mines.reserve(n);

		for (int i = 0, x, y; i < 2 * n; i++) {
			cin >> x >> y;
			if (x == 0) {
				miners.push_back(abs(y));
			} else {
				mines.push_back(abs(x));
			}
		}

		//sqrt(x1^2 + y1^2) + sqrt(x2^2 + y2^2)
		//sqrt(x1^2 + y2^2) + sqrt(x2^2 + y1^2)
		//(x1^2 * x2^2

		sort(miners.begin(), miners.end());
		sort(mines.begin(), mines.end());

		double ans = 0;
		for (int i = 0; i < n; i++) {
			ans += sqrt((long long)miners[i] * miners[i] + (long long)mines[i] * mines[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}