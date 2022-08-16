#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<string> strings;

	string cur;
	for (int i = 0; i < n; i++) {
		if (s[i] >= s[0]) {
			strings.push_back(cur);
			cur.clear();
		}
		if (s[i] > s[0]) {
			break;
		}
		cur += s[i];
	}

	strings.push_back(cur);

	strings.erase(remove_if(strings.begin(), strings.end(), [&](const string &t) {
		return t.empty();
	}), strings.end());

	int a = 0;
	for (int i = 1, ii = 0; i < (int) strings.size(); i++) {
		bool equal = true;
		for (int j = 0; j < (int) min(strings[i].size(), strings[ii].size()); j++) {
			equal &= strings[i][j] == strings[ii][j];
		}

		if (equal) {
			if (strings[i].size() < strings[ii].size()) {
				break;
			} else if (strings[i].size() == strings[ii].size()) {
				ii += 1;
			} else {
				ii = 0, a = i;
			}
		} else {
			if (strings[i] < strings[ii]) {
				ii = 0, a = i;
			} else {
				break;
			}
		}
	}

	s.clear();
	for (int i = 0; i <= a; i++) {
		s += strings[i];
	}

	while (s.size() < k) {
		s += s;
	}

	s.resize(k);
	cout << s << '\n';
	return 0;
}