#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

set<string> solve(string& s) {
	set<string> res;
	int n = s.size();
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			string t = s.substr(0, i);
			bool b = 1;
			for (int j = i; j < n; j += i) {
				if (t != s.substr(j, i)) {
					b = 0;
					break;
				}
			}
			if (b) res.insert(t);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2; cin >> s1 >> s2;
	set<string> a = solve(s1);
	set<string> b = solve(s2);
	int ans = 0;
	for (const string& s : a) ans += b.find(s) != b.end();
	cout << ans;
	return 0;
}