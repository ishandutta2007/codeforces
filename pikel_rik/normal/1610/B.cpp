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

		vector<int> a(n);
		for (auto &x : a) cin >> x, --x;

		int not_palindrome = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] != a[n - i - 1]) {
				not_palindrome = i;
				break;
			}
		}

		if (not_palindrome == -1) {
			cout << "YES\n";
			continue;
		}

		bool possible = false;
		for (int c : {a[not_palindrome], a[n - not_palindrome - 1]}) {
			auto b = a;
			b.erase(remove_if(b.begin(), b.end(), [&](int x) { return x == c; }), b.end());

			bool is_palindrome = true;
			for (int i = 0; i < (int) b.size(); i++) {
				is_palindrome &= *(b.begin() + i) == *(b.rbegin() + i);
			}
			possible |= is_palindrome;
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}