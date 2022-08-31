#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p(n);
	for (auto &x : p) cin >> x, x = abs(x);

	vector<int> temp = p;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	vector<vector<int>> pos(temp.size());
	for (int i = 0; i < n; i++) {
		p[i] = lower_bound(temp.begin(), temp.end(), p[i]) - temp.begin();
		pos[p[i]].push_back(i);
	}

	long long ans = 0;
	for (int i = int(temp.size()) - 1; i >= 0; i--) {
		vector<int> cnt(n);
		int cur_cnt = 0;
		for (int j = 0; j < n; j++) {
			if (p[j] == i) {
				cnt[j] = cur_cnt;
			} else if (p[j] < i) {
				cur_cnt += 1;
			}
		}

		vector<vector<long long>> dp(pos[i].size(), vector<long long>(pos[i].size(), -1));

		auto recurse = [&](int cur_pos, int cur_neg, const auto &self) -> long long {
			if (cur_pos == int(pos[i].size()))
				return 0;
			long long &ans = dp[cur_pos][cur_neg];
			if (ans != -1)
				return ans;
			ans = cur_cnt - cnt[pos[i][cur_pos]] + self(cur_pos + 1, cur_neg, self);
			ans = min(ans, cnt[pos[i][cur_pos]] + cur_pos - cur_neg + self(cur_pos + 1, cur_neg + 1, self));
			return ans;
		};
		ans += recurse(0, 0, recurse);
	}
	cout << ans << '\n';
	return 0;
}