#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> squares;
	for (int i = 1; i * i <= 2000000000; i += 2) {
		squares.push_back(i * i);
		//(2 * c - 1 = i * i => c = (i * i + 1) / 2
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		//a^2 + b^2 = c^2
		//(b + c) + b^2 = c^2
		//(b + c) = c^2 - b^2
		//(b + c) = (c - b) (c + b)
		//c - b = 1
		//c = b + 1

		int lo = 0, hi = int(squares.size()) - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if ((squares[mid] + 1) / 2 <= n)
				lo = mid;
			else hi = mid - 1;
		}

		cout << lo << '\n';
	}
	return 0;
}