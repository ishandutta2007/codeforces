#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int c1 = 0, c2 = 0;
	for (char ch : s) {
		c2 += ch == ')';
	}

	int pos = -1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			c1++;
			if (c1 == c2) {
				pos = i;
				break;
			}
		} else {
			c2--;
			if (c1 == c2) {
				pos = i;
				break;
			}
		}
	}

	vector<int> ans;
	if (pos != -1) {
		for (int i = 0; i <= pos; i++) {
			if (s[i] == '(') {
				ans.push_back(i);
			}
		}

		for (int i = pos + 1; i < s.length(); i++) {
			if (s[i] == ')') {
				ans.push_back(i);
			}
		}
	}

	if (ans.empty()) {
		cout << "0\n";
	} else {
		cout << 1 << '\n';
		cout << ans.size() << '\n';
		for (int i : ans) cout << i + 1 << ' '; cout << '\n';
	}
	return 0;
}