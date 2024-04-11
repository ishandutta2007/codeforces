#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << max(max(b - a, c - a) + 1, 0) << " " << max(max(a - b, c - b) + 1, 0) << " " << max(max(a - c, b - c) + 1, 0) << endl;
	}
}