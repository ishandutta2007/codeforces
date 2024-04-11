#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n_days, n_cores, m;
vector< pair<int, int> > E[N];

int64_t sumC[N];
int64_t sumPC[N];

void update(int64_t bit[], int i, int64_t v) {
	for (; i < N; i += i & -i) {
		bit[i] += v;
	}
}

int64_t get(int64_t bit[], int i) {
	int64_t res = 0;
	for (; i; i -= i & -i) {
		res += bit[i];
	}
	return res;
}

int find_pos() {
	int l = 1, r = N - 1;
	int res = N - 1;
	while (l <= r) {
		int m = l + r >> 1;
		if (get(sumC, m) >= n_cores) {
			res = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n_days >> n_cores >> m;
	while (m--) {
		int l, r, c, p;
		cin >> l >> r >> c >> p;
		E[l].push_back(make_pair(p, +c));
		E[r + 1].push_back(make_pair(p, -c));
	}

	int64_t ans = 0;

	for (int day = 1; day <= n_days; ++day) {
		while (!E[day].empty()) {
			update(sumC, E[day].back().first, E[day].back().second);
			update(sumPC, E[day].back().first, 1LL * E[day].back().first * E[day].back().second);
			E[day].pop_back();
		}
		int pos = find_pos();
		if (get(sumC, pos) <= n_cores) {
			ans += get(sumPC, pos);
		} else {
			ans += get(sumPC, pos - 1);
			int last = get(sumC, pos - 1);
			ans += 1LL * pos * (n_cores - last);
		}
	}

	cout << ans << endl;

	return 0;
}