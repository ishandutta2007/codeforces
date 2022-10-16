#include <bits/stdc++.h>
using namespace std;

#define int long long

void output(vector<int> h, int p1, int p2) {
	int mn = min(p1, p2);
	for (int i: h) mn = min(mn, i);

	if (mn < 0) {
		for (int &i: h) i -= mn;
		p1 -= mn; p2 -= mn;
	}

	cout << "YES\n";
	for (int i: h) cout << i << ' ';
		cout << '\n';
	cout << p1 << ' ' << p2 << '\n';
}

bool try_solve(int n, vector<int> d1, vector<int> d2, int p1, int p2, vector<int> &h) {
	if (p1 == p2) return 0;

	multiset<int> m1, m2;
	for (int i: d1) m1.insert(i);
	for (int i: d2) m2.insert(i);

	h.clear();
	while (m1.size() && m2.size()) {
		int mx = max(*m1.rbegin(), *m2.rbegin());

		if (mx == *m1.rbegin()) {
			int pos, dist1, dist2;
			if (mx >= abs(p1 - p2)) {
				dist1 = mx;
				dist2 = dist1 - abs(p1 - p2);
				pos = p1 + mx;
			} else {
				dist1 = mx;
				dist2 = abs(p1 - p2) - dist1;
				pos = p1 + mx;
			}

			if (m2.find(dist2) == m2.end()) {
				return 0;
			}

			m1.erase(m1.find(dist1));
			m2.erase(m2.find(dist2));
			h.push_back(pos);
		} else {
			int pos, dist1, dist2;
			if (mx >= abs(p1 - p2)) {
				dist2 = mx;
				dist1 = dist2 - abs(p1 - p2);
				pos = p1 - dist1;
			} else {
				dist2 = mx;
				dist1 = abs(p1 - p2) - dist2;
				pos = p1 + dist1;
			}

			if (m1.find(dist1) == m1.end()) {
				return 0;
			}

			m1.erase(m1.find(dist1));
			m2.erase(m2.find(dist2));
			h.push_back(pos);
		}
	}

	return 1;
}

void solve() {
	int n; cin >> n;
	vector<int> d1(n), d2(n);
	for (int &i: d1) cin >> i;
	for (int &i: d2) cin >> i;

	sort(d1.begin(), d1.end());
	sort(d2.begin(), d2.end());
	if (d1 == d2) {
		output(d1, 0, 0);
		return;
	}

	vector<int> h;
	for (int i = 0; i < n; i++) {
		if (try_solve(n, d1, d2, 0, d1[0]+d2[i], h)) {
			output(h, 0, d1[0]+d2[i]);
			return;
		}
		if (try_solve(n, d1, d2, 0, abs(d1[0]-d2[i]), h)) {
			output(h, 0, abs(d1[0]-d2[i]));
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}