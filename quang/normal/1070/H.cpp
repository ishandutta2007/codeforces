#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
const int MOD1 = 119 * (2 << 23) + 1;
const int MOD2 = 1e9 + 7;
const int BASE = 10007;

inline int add(int u, int v, int MOD) {
	u += v;
	if (u >= MOD) u -= MOD;
	return u;
}

inline int mul(int u, int v, int MOD) {
	return (long long)u * v % MOD;
}

map<pair<int, int> , pair<string, int> > m[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		set<pair<int, int> > used[10];
		for (int i = 0; i < s.size(); i++) {
			int cur1 = 0;
			int cur2 = 0;
			for (int j = i; j < s.size(); j++) {
				cur1 = add(mul(cur1, BASE, MOD1), s[j], MOD1);
				cur2 = add(mul(cur2, BASE, MOD2), s[j], MOD2);
				pair<int, int> val(cur1, cur2);
				if (used[j - i + 1].count(val)) continue;
				used[j - i + 1].insert(val);
				auto foo = m[j - i + 1][pair<int, int> (cur1, cur2)];
				foo.second++;
				foo.first = s;
				m[j - i + 1][pair<int, int> (cur1, cur2)] = foo;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		int cur1 = 0, cur2 = 0;
		for (int i = 0; i < s.size(); i++) {
			cur1 = add(mul(cur1, BASE, MOD1), s[i], MOD1);
			cur2 = add(mul(cur2, BASE, MOD2), s[i], MOD2);
		}
		auto foo = m[s.size()][pair<int, int>(cur1, cur2)];
		if (foo.second == 0) {
			cout << 0 << " -" << endl;
		} else {
			cout << foo.second << " " << foo.first << endl;
		}
	}
	return 0;	
}