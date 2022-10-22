#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 1e5 + 2;

int get(set <int> id0, set <int> id1, vector <int> need) {
	int n = need.size();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (need[i] == 0) {
			if (id0.find(i) != id0.end()) {
				id0.erase(i);
				continue;
			}
			if (id0.empty()) return mod * mod;
			ans += *id0.begin() - i;
			id1.erase(i);
			id1.insert(*id0.begin());
			id0.erase(id0.begin());
		}
		else {
			if (id1.find(i) != id1.end()) {
				id1.erase(i);
				continue;
			}
			if (id1.empty()) return mod * mod;
			ans += *id1.begin() - i;
			id0.erase(i);
			id0.insert(*id1.begin());
			id1.erase(id1.begin());
		}
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;

		vector <int> a(n);

		int cnt = 0;

		set <int> id0, id1;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] &= 1;
			if (a[i] == 1) {
				cnt++;
				id1.insert(i);
			}
			else id0.insert(i);
		}

		int ans = mod * mod;

		if (n & 1) {
			vector <int> need(n);
			for (int i = 0; i < n; i += 2)
				need[i] = 1;
			if (cnt == n / 2) {
				for (auto& x : need) x ^= 1;
			}
			ans = get(id0, id1, need);
		}
		else {
			vector <int> need(n), need2(n, 1);
			for (int i = 0; i < n; i += 2)
				need[i] = 1, need2[i] = 0;
			ans = min(get(id0, id1, need), get(id0, id1, need2));
		}

		cout << (ans == mod * mod ? -1 : ans) << '\n';

	}

	return 0;
}