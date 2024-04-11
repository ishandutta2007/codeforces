#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int solve(vector<int> a, int bit = 29) {
	if (bit < 0) return 0;
	if (a.size() <= 1) return 0;
	vector<int> l, r;
	for (int i : a) {
		if (i & (1 << bit)) r.push_back(i);
		else l.push_back(i);
	}
	int x = solve(l, bit - 1) + max(0, (int)r.size() - 1);
	int y = solve(r, bit - 1) + max(0, (int)l.size() - 1);
	return min(x, y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << solve(a);
	return 0;
}