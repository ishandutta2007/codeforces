#include <bits/stdc++.h>
using namespace std;

template<typename T>
bool is_prime(T x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; (T) i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		string s;
		cin >> s;

		string ans;
		for (char &ch : s) {
			int digit = ch - '0';
			if (digit != 2 && digit != 3 && digit != 5 && digit != 7) {
				ans = string(1, '0' + digit);
				break;
			}
		}

		if (!ans.empty()) {
			cout << (int) ans.length() << '\n' << ans << '\n';
			continue;
		}

		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				string temp = string(1, s[i]) + string(1, s[j]);
				if (!is_prime(stoi(temp))) {
					ans = temp;
				}
			}
		}

		if (!ans.empty()) {
			cout << (int) ans.length() << '\n' << ans << '\n';
			continue;
		}

		assert(false);
	}
	return 0;
}