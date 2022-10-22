#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	string s;
	cin >> n >> s;
	s += '+';
	vector<int> pos = {0};
	deque<int> dq;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != s[i - 1]) {
			pos.push_back(i);
		}
	}
	for (int i = 1; i < pos.size(); ++i) {
		dq.push_back(pos[i] - pos[i - 1]);
	}
	assert(accumulate(dq.begin(), dq.end(), 0) == n);

	int ans = 0;
	int i = 0;
	while(!dq.empty()) {
		++ans;
		while(i < dq.size() && dq[i] == 1) {
			++i;
		}
		assert(i <= dq.size());
		if (i < dq.size()) {
			--dq[i];
		}
		else {
			--i;
			dq.pop_back();
		}
		if (dq.empty()) break;
		if (i > 0) --i;
		dq.pop_front();
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}