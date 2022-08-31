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

		string s;
		cin >> s;

		int c = 0;
		for (; !s.empty() && s.back() == ')'; c++, s.pop_back());

		cout << (c > n - c ? "Yes" : "No") << '\n';
	}
	return 0;
}