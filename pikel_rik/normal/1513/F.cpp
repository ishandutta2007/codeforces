#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	long long ans = 0;
	vector<pair<int, int>> lefts, rights;

	for (int i = 0; i < n; i++) {
		ans += abs(a[i] - b[i]);
		if (a[i] < b[i]) {
			lefts.emplace_back(a[i], b[i]);
		} else if (a[i] > b[i]) {
			rights.emplace_back(b[i], a[i]);
		}
	}

	sort(lefts.begin(), lefts.end(), [&](const auto &p1, const auto &p2) {
		return p1.second > p2.second;
	});

	sort(rights.begin(), rights.end(), [&](const auto &p1, const auto &p2) {
		return p1.second > p2.second;
	});

	int inter = 0;
	for (int rot = 0; rot < 2; rot++) {
		int mn = INT_MAX;
		for (int i = 0, j = 0; i < lefts.size(); i++) {
			while (j < rights.size() && rights[j].second >= lefts[i].second) {
				mn = min(mn, rights[j].first);
				j += 1;
			}
			if (mn > lefts[i].first) {
				inter = max(inter, lefts[i].second - mn);
			} else {
				inter = max(inter, lefts[i].second - lefts[i].first);
			}
		}
		lefts.swap(rights);
	}
	ans -= 2 * inter;
	cout << ans << '\n';
	return 0;
}