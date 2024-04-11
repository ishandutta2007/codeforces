#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	auto solve = [&](int n, string s, string t) {
		reverse(t.begin(), t.end());
		map<pair<char, char>, int> g;
		for (int i = 0; i < n; ++i) {
			if (s[i] > t[i]) swap(s[i], t[i]);
			auto p = make_pair(s[i], t[i]);
			++g[p];
		}
		if (n % 2 == 0) {
			for (auto p : g) {
				if (p.second % 2) {
					return false;
				}
			}
			return true;
		}
		int c = 0;
		for (auto p : g) {
			if (p.second % 2) {
				if (p.first.first != p.first.second)
					return false;
				++c;
			}
		}
		return c == 1;
	};
	for (int Case = 1; Case <= T; ++Case) {
		int n;
		string s, t;
		cin >> n >> s >> t;	
		cout << (solve(n, s, t) ? "YES" : "NO") << '\n';
	}
}