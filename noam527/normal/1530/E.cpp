#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
string s;

void solve() {
	cin >> s;
	n = s.size();
	map<char, int> m;
	for (auto &i : s) m[i]++;
	if (m.size() == 1 || n <= 2) {
		sort(s.begin(), s.end());
		cout << s << '\n';
		return;
	}
	for (const auto &p : m) {
		if (p.second == 1) {
			cout << p.first;
			for (const auto &q : m)
				if (p.first != q.first)
					cout << string(q.second, q.first);
			cout << '\n';
			return;
		}
	}
	auto mn = *m.begin();
	auto mn2 = *(next(m.begin()));
	if (n + 2 >= 2 * mn.second) {
		string t(n, '0');
		t[0] = t[1] = mn.first;
		mn.second -= 2;
		for (int i = 3; mn.second > 0; i += 2) {
			t[i] = mn.first;
			mn.second--;
		}
		sort(s.begin(), s.end());
		int nxt = 0;
		while (s[nxt] == mn.first) nxt++;
		for (int i = 0; i < n; i++) {
			if (t[i] == '0') {
				t[i] = s[nxt++];
			}
		}
		cout << t << '\n';
		return;
	}
	if (m.size() >= 3) {
		string t(n, '0');
		t[0] = mn.first, t[1] = mn2.first;
		mn.second--, mn2.second--;
		int nxt = 2;
		while (mn.second > 0) {
			mn.second--;
			t[nxt++] = mn.first;
		}
		t[nxt++] = next(next(m.begin()))->first;
		next(next(m.begin()))->second--;
		m.begin()->second = 0;
		next(m.begin())->second = 0;
		while (mn2.second > 0) {
			mn2.second--;
			t[nxt++] = mn2.first;
		}
		for (const auto &p : m) {
			for (int j = 0; j < p.second; j++)
				t[nxt++] = p.first;
		}
		cout << t << '\n';
		return;
	}
	sort(s.begin(), s.end());
	cout << s[0] << s.back();
	s.pop_back();
	reverse(s.begin(), s.end());
	s.pop_back();
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}