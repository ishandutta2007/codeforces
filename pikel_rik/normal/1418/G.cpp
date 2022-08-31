#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;

	vector<uint64_t> three(40);
	three[0] = 1;
	for (int i = 1; i < 40; i++) {
		three[i] = 3 * three[i - 1];
	}

	vector<uint64_t> hash(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 40; j++) {
			hash[i] += three[j] * (rng() % 3);
		}
	}

	auto xor_add = [&](uint64_t a, uint64_t b) -> uint64_t {
		uint64_t c = 0;
		for (int j = 0; j < 40; j++) {
			c += three[j] * ((a % 3 + b % 3) % 3);
			a /= 3, b /= 3;
		}
		return c;
	};

	vector<vector<int>> pos(n);

	map<uint64_t, int> mp;

	vector<uint64_t> pref(n);
	pref[0] = hash[a[0]];
	mp[0] += 1, mp[pref[0]] += 1;

	long long ans = 0;
	for (int i = 1, last = -1; i < n; i++) {
		pos[a[i]].push_back(i);
		pref[i] = xor_add(pref[i - 1], hash[a[i]]);
		if (pos[a[i]].size() > 3 && *(pos[a[i]].rbegin() + 3) > last) {
			int new_last = *(pos[a[i]].rbegin() + 3);
			for (int j = last; j < new_last; j++) {
				mp[j == -1 ? 0 : pref[j]] -= 1;
			}
			last = new_last;
		}
		ans += mp[pref[i]]++;
	}
	cout << ans << '\n';
	return 0;
}