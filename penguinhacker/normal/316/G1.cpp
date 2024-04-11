#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, l[10], r[10];
string s, p[10];
set<string> ans;

void check(string t) {
	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int j = 0; j + t.size() - 1 < p[i].size(); ++j) {
			cur += t == p[i].substr(j, t.size());
		}
		if (cur < l[i] || cur > r[i]) return;
	}
	ans.insert(t);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> n;
	for (int i = 0; i < n; ++i) cin >> p[i] >> l[i] >> r[i];
	for (int i = 0; i < s.size(); ++i) for (int j = 1; j <= s.size() - i; ++j) check(s.substr(i, j));
	cout << ans.size();
	return 0;
}