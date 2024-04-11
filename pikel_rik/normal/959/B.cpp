#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, m;
	cin >> n >> k >> m;

	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	map<string, int> group;
	vector<vector<int>> groups(n);
	for (int i = 0, x; i < k; i++) {
		cin >> x, groups[i].resize(x);
		for (auto &s_id : groups[i]) {
			cin >> s_id;
			group[s[--s_id]] = i;
		}
		sort(groups[i].begin(), groups[i].end(), [&](auto s_id1, auto s_id2) {
			return a[s_id1] < a[s_id2];
		});
	}

	long long ans = 0;
	for (int i = 0; i < m; i++) {
		string word;
		cin >> word;
		int g_id = group[word];
		ans += a[groups[g_id][0]];
	}
	cout << ans << '\n';
	return 0;
}