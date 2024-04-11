#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> p(n+1);

	int id;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		p[i] = p[i-1];
		if (x < m) p[i]--;
		else if (x > m) p[i]++;
		else id = i;
	}

	int ans = 0;
	map<int, int> cnt;
	for (int i = 0; i < id; i++) {
		cnt[p[i]]++;
	}
	for (int i = id; i <= n; i++) {
		ans += cnt[p[i]];
		ans += cnt[p[i]-1];
	}
	cout << ans << '\n';

	return 0;
}