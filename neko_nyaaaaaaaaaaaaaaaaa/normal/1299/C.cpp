// I copy pasted my own solution from https://open.kattis.com/problems/accesspoints

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool agb(pair<int, int> a, pair<int, int> b) {
	return a.first*b.second > b.first*a.second;
}

void merge(pair<int, int> &a, pair<int, int> b) {
	a.first += b.first;
	a.second += b.second;
}

void solve(vector<int> a, int n) {
	vector<pair<int, int>> s;
	for (int x: a) {
		if (s.empty()) {
			s.push_back({x, 1});
		} else {
			pair<int, int> nxt(x, 1);
			while (s.size() && agb(s.back(), nxt)) {
				merge(nxt, s.back());
				s.pop_back();
			}
			s.push_back(nxt);
		}
	}

	int i = 0;
	vector<double> ans(n);
	for (auto [sum, cnt]: s) {
		double avg = sum*1.0/cnt;
		while (cnt--) {
			ans[i] += avg;
			i++;
		}
	}
	for (double u: ans) cout << u << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve(a, n);

	return 0;
}