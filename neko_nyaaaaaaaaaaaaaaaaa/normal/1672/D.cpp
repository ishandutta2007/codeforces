#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int, int>> parse(vector<int> a) {
	vector<pair<int, int>> ans;
	int cnt = 1, prv = a[0];
	for (int i = 1; i < a.size(); i++) {
		if (a[i] != prv) {
			ans.emplace_back(prv, cnt);
			cnt = 0; prv = a[i];
		}
		cnt++;
	} 
	ans.emplace_back(prv, cnt);
	return ans;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int &i: a) cin >> i;
	for (int &i: b) cin >> i;

	vector<pair<int, int>> p1 = parse(a), p2 = parse(b);

	if (p2.size() > p1.size()) {
		cout << "NO\n";
		return;
	}

	map<int, int> owe; set<int> seen;
	for (int i = p1.size()-1, j = p2.size()-1; i >= 0 || j >= 0;) {
		if (p1[i].first == p2[j].first) {
			if (p1[i].second <= p2[j].second) {
				owe[p1[i].first] += abs(p1[i].second - p2[j].second);
				seen.insert(p1[i].first); i--; j--;
			} else {
				// >= 
				if (abs(p1[i].second - p2[j].second) > owe[p1[i].first]) {
					cout << "NO\n";
					return;
				} else {
					owe[p1[i].first] -= abs(p1[i].second - p2[j].second);
					seen.insert(p1[i].first); i--, j--;
				}
			}
		} else {
			if (!seen.count(p1[i].first)) {
				cout << "NO\n"; return;
			} else {
				if (owe[p1[i].first] < p1[i].second) {
					cout << "NO\n"; return;
				} else {
					owe[p1[i].first] -= p1[i].second;
					seen.insert(p1[i].first); i--;
				}
			}
		}
	}
	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}