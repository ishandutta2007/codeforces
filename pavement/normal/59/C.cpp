#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	string s;
	cin >> k >> s;
	int l = s.size();
	vector<int> q;
	set<char> u;
	for (int i = 0; i < k; i++)
		u.insert(i + 'a');
	for (char c : s)
		if (c != '?')
			u.erase(c);
	for (int i = 0; i < l / 2; i++)
		if (s[i] == '?' && s[l - i - 1] == '?') {
			q.push_back(i);
		} else if (s[i] == '?') {
			s[i] = s[l - i - 1];
		} else if (s[l - i - 1] == '?') {
			s[l - i - 1] = s[i];
		} else if (s[i] != s[l - i - 1]) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	if (l % 2 != 0 && s[l / 2] == '?') q.push_back(l / 2);
	if (q.size() < u.size()) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	reverse(q.begin(), q.end());
	for (int i : q) {
		if (!u.empty()) {
			s[i] = s[l - i - 1] = *u.rbegin();
			u.erase(--u.end());
		} else {
			s[i] = s[l - i - 1] = 'a';
		}
	}
	cout << s << '\n';
}