#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long first_sum = 0, second_sum = 0;
	vector<int> first, second;

	int last = -1;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x > 0) {
			first.push_back(x);
			first_sum += x;
			last = 0;
		} else {
			second.push_back(-x);
			second_sum -= x;
			last = 1;
		}
	}

	if (first_sum > second_sum) {
		cout << "first\n";
	} else if (second_sum > first_sum) {
		cout << "second\n";
	} else if (first > second) {
		cout << "first\n";
	} else if (second > first) {
		cout << "second\n";
	} else {
		cout << (last == 0 ? "first" : "second") << '\n';
	}
	return 0;
}