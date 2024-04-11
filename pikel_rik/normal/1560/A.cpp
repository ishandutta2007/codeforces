#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> good;

	for (int i = 1; (int) good.size() < 1000; i++) {
		if (i % 3 != 0 && i % 10 != 3) {
			good.push_back(i);
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;
		cout << good[--k] << '\n';
	}
	return 0;
}