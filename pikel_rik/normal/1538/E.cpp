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

		map<string, pair<string, long long>> mp;

		auto find_hahas = [&](const string &s) -> int {
			int ans = 0;
			for (int i = 0; i + 4 <= s.length(); i++) {
				ans += s.substr(i, 4) == "haha";
			}
			return ans;
		};

		string last;
		for (int i = 0; i < n; i++) {
			string var, op, op1, op2;
			cin >> var >> op;

			last = var;

			if (op == ":=") {
				cin >> op1;
				mp[var] = make_pair(op1, find_hahas(op1));
				continue;
			}

			cin >> op1 >> op >> op2;

			auto t1 = mp[op1];
			auto t2 = mp[op2];

			auto &res = mp[var];
			res.first = t1.first + t2.first;
			res.second = t1.second + t2.second;

			for (int j = 0; j < t1.first.length(); j++) {
				if (j + 4 > t1.first.length() && j + 4 <= res.first.length()) {
					res.second += res.first.substr(j, 4) == "haha";
				}
			}

			if (t1.first.length() >= 3 && t2.first.length() >= 3) {
				while (t1.first.length() > 3) {
					t1.first.pop_back();
				}
				while (t2.first.length() > 3) {
					t2.first.erase(t2.first.begin());
				}
			}
			res.first = t1.first + t2.first;
		}

		cout << mp[last].second << '\n';
	}
	return 0;
}