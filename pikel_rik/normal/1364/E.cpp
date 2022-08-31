#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1 << 11;

int n, ans[N], memo[N][N];

int query(int i, int j) {
	if (i > j) swap(i, j);
	if (memo[i][j] == -1) {
		cout << "? " << i + 1 << ' ' << j + 1 << endl;
		cin >> memo[i][j];
	}
	return memo[i][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(memo, -1, sizeof(memo));
	memset(ans, -1, sizeof(ans));

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	cin >> n;
	int lg = 32 - __builtin_clz(n - 1);

	vector<int> cur(n);
	iota(cur.begin(), cur.end(), 0);

	int zero = -1;
	for (int c = lg; cur.size() > 2;) {
		int i = -1;
		while (true) {
			int qi = rng() % cur.size(), qj;
			while ((qj = rng() % cur.size()) == qi);
			if (2 * __builtin_popcount(query(cur[qi], cur[qj])) <= c) {
				i = qi;
				break;
			}
		}

		ans[cur[i]] = (1 << lg) - 1;
		for (int idx : cur) {
			if (idx != cur[i]) {
				ans[cur[i]] &= query(idx, cur[i]);
			}
		}

		if (ans[cur[i]] == 0) {
			zero = cur[i];
			break;
		}
		vector<int> new_cur;
		for (int idx : cur) {
			if (idx != cur[i] && query(idx, cur[i]) == ans[cur[i]]) {
				new_cur.push_back(idx);
			}
		}
		if (new_cur.size() == 1) {
			zero = new_cur.front();
			break;
		}
		c = __builtin_popcount(ans[cur[i]]);
		cur.swap(new_cur);
	}

	if (zero != -1) {
		ans[zero] = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i] == -1) {
				ans[i] = query(i, zero);
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (i == cur[0] || i == cur[1] || ans[i] != -1) continue;
			if (zero != -1) {
				if (i != zero) {
					 ans[i] = query(i, zero);
				} else ans[i] = 0;
			} else {
				int q0 = query(i, cur[0]), q1 = query(i, cur[1]);
				ans[i] = min(q0, q1);
				if (q0 < q1) {
					zero = cur[0];
				} else if (q1 < q0) {
					zero = cur[1];
				}
			}
		}
		ans[zero] = 0;
		ans[zero ^ cur[0] ^ cur[1]] = query(cur[0], cur[1]);
	}

	cout << "! ";
	for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << endl;
	return 0;
}