#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
int64_t t;
int p[N];

template<class T> struct BIT {
	T a[N];

	BIT() {
		memset(a, 0, sizeof a);
	}

	void update(int i, T v) {
		for (; i < N; i += i & -i) {
			a[i] += v;
		}
	}

	T get(int i) {
		T res = 0;
		for (; i; i -= i & -i) {
			res += a[i];
		}
		return res;
	}
};

BIT<int> cnt;
BIT<int64_t> sum;

int64_t get_prefix_time(int till, int prefix_cnt) {
	if (prefix_cnt <= 0) return 0;
	int l = 0, r = till;
	while (l <= r) {
		int mid = l + r >> 1;
		int cur = cnt.get(mid);
		if (cur == prefix_cnt) {
			return sum.get(mid);
		}
		if (cur < prefix_cnt) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	assert(false);
}

int find_last() {
	int l = 1, r = n;
	int res = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		int all_cnt = cnt.get(mid);
		int prefix_cnt = all_cnt;
 		if (all_cnt % m == 0) {
 			prefix_cnt -= m;
 		} else {
 			prefix_cnt -= all_cnt % m;
 		}
		int64_t cur = get_prefix_time(mid, prefix_cnt);
		cur += sum.get(mid);
		//cerr << mid << ' ' << all_cnt << ' ' << prefix_cnt << ' ' << get_prefix_time(mid, prefix_cnt) << ' ' << cur << endl;
		if (cur <= t) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}

		vector< pair<int, int> > tasks;
		for (int i = 1; i <= n; ++i) {
			tasks.push_back(make_pair(p[i], i));
		}

		sort(tasks.begin(), tasks.end());
		int ans = 0, best = t;
		for (int i = 0; i < tasks.size(); ++i) {
			int d = tasks[i].first;
			int pos = tasks[i].second;
			cnt.update(pos, +1);
			sum.update(pos, +d);
			if (i + 1 < tasks.size() && tasks[i + 1].first == d) continue;

			int last = find_last();
			int cur = cnt.get(last);
			if (ans < cur) {
				ans = cur;
				best = d;
			}
		}

		cout << ans << ' ' << best << '\n';

		for (int i = 1; i <= n; ++i) {
			cnt.update(i, -1);
			sum.update(i, -p[i]);
		}
	}
	return 0;
}