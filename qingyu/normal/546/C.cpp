#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k1, k2;
	cin >> n;
	queue<int> f1, f2;
	cin >> k1;
	for (int i = 0; i < k1; ++i) {
		int x;
		cin >> x;
		f1.push(x);
	}
	cin >> k2;
	for (int i = 0; i < k2; ++i) {
		int x;
		cin >> x;
		f2.push(x);
	}
	for (int c = 0; c < 1e6; ++c) {
		if (f1.empty()) {
			cout << c << " 2\n";
			return 0;
		}
		if (f2.empty()) {
			cout << c << " 1\n";
			return 0;
		}
		int x = f1.front(); f1.pop();
		int y = f2.front(); f2.pop();
		if (x > y) {
			f1.push(y);
			f1.push(x);
		}
		else {
			f2.push(x);
			f2.push(y);
		}
	}
	cout << -1 << '\n';
}