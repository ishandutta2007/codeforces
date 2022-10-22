#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n, k; cin >> n >> k;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		s.insert(x);
	}
	int mx = *s.rbegin();
	int mex = 0;
	while(s.find(mex) != s.end())
		++mex;
	if (mx + 1 == mex) {
		cout << n + k << "\n";
		return;
	}
	int nxt = (mx + mex + 1) / 2;
	n += k && s.find(nxt) == s.end();
	cout << n << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}