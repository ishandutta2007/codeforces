#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
map<char, int> m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	m['N'] = 0, m['E'] = 1, m['S'] = 2, m['W'] = 3;
	while (t--) {
		string s;
		cin >> s;
		int ans = 0;
		set<pair<pair<int, int>, pair<int, int>>> se;
		pair<int, int> c = { 0, 0 };
		for (auto &i : s) {
			pair<int, int> n = { c.first + dx[m[i]], c.second + dy[m[i]] };
			if (se.count({ min(c, n), max(c, n) }))
				ans++;
			else
				ans += 5;
			se.insert({ min(c, n), max(c, n) });
			c = n;
		}
		cout << ans << endl;
	}
}