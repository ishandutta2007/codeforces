#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int prefix_function(const string& s) {
	int n = s.size();
	assert(n > 0);
	vector<int> ans(n);
	for (int i = 1; i < n; ++i) {
		int j = ans[i - 1];
		while(j > 0 && s[i] != s[j]) j = ans[j - 1];
		if (s[i] == s[j]) ++j;
		ans[i] = j;
	}
	return ans[n - 1];
}

int n;
string s;

void solve() {
	cin >> s, n = s.size();
	int i = 0;
	for (; i < s.size() / 2 && s[i] == s[n - i - 1]; ++i);
	string first = s.substr(0, i);
	string last = first;
	reverse(last.begin(), last.end());
	s = s.substr(i, n - 2 * i);
	string sr = s;
	reverse(sr.begin(), sr.end());
	string t = s + '#' + sr;
	int len = prefix_function(t);
	string ans = s.substr(0, len);
	t = sr + '#' + s;
	len = prefix_function(t);
	if (len > ans.size()) {
		ans = s.substr(s.size() - len);
	}
	ans = first + ans + last;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}