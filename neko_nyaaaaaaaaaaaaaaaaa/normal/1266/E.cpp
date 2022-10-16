#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n+1);
	int mov = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mov += a[i];
	}

	map<pair<int, int>, int> rew;
	vector<int> bonus(n+1);
	int q; cin >> q;
	while (q--) {
		int s, t, u; cin >> s >> t >> u;

		if (rew.find({s, t}) != rew.end()) {
			int g = rew[{s, t}];
			bonus[g]--;

			if (bonus[g] < a[g]) {
				mov++;
			}

			rew.erase(rew.find({s, t}));
		}

		if (u != 0) {
			rew[{s, t}] = u;
			if (bonus[u] < a[u]) {
				mov--;
			}
			bonus[u]++;
		}

		cout << mov << '\n';
	}

	return 0;
}