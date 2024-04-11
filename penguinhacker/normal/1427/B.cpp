#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int wins = count(s.begin(), s.end(), 'W');
		if (k + wins >= n) {
			cout << 2 * n - 1 << "\n";
			continue;
		}
		if (wins == 0) {
			cout << max(0, 2 * k - 1) << "\n";
			continue;
		}
		vector<int> pos, gap;
		int ans = wins + 2 * k;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'W') {
				pos.push_back(i);
			}
		}
		for (int i = 1; i < pos.size(); ++i) {
			gap.push_back(pos[i] - pos[i - 1] - 1);
		}
		sort(gap.rbegin(), gap.rend());
		while(!gap.empty() && gap.back() <= k) {
			++ans;
			k -= gap.back();
			gap.pop_back();
		}
		cout << ans << "\n";
	}
	return 0;
}