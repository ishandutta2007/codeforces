#include <bits/stdc++.h>
using namespace std;

struct HASH{
	size_t operator()(const pair<int,int>&x)const{
		return hash<long long>()(((long long)x.first)^(((long long)x.second) << 32));
	}
};

pair<int, int> normalize(int x, int y) {
	int g = __gcd(x, y);
	x /= g; y /= g;
	return {x, y};
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int q; cin >> q;
	int cnt = 0;
	unordered_map<long long, unordered_set<pair<int, int>, HASH>> cir;
	unordered_map<pair<int, int>, int, HASH> L, S;

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;

		if (t == 3) {
			tie(x, y) = normalize(x, y);
			cout << cnt - L[{x, y}] - 2*S[{x, y}] << '\n';
		} else {
			long long c = 1LL*x*x + 1LL*y*y;
			if (t == 2) {
				t = -1;
				cir[c].erase(cir[c].find({x, y}));
			}

			L[normalize(x, y)] += t;
			for (auto [_x, _y]: cir[c]) {
				S[normalize(x + _x, y + _y)] += t;
			}

			if (t == 1) {
				cir[c].insert({x, y});
			}

			cnt += t;
		}
	}

	return 0;
}