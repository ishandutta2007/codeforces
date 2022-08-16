#include <bits/stdc++.h>
using namespace std;

template<typename T, typename L = T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<L> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() { }

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
		build(v, 1, 0, n - 1);
	}

	template<typename U>
	void build(const std::vector<U> &v, int i, int l, int r) {
		if (l == r) {
			t[i] = T(v[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(v, i << 1, l, mid);
		build(v, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	void push(int x, int l, int r) {
		if (lazy[x]) {
			t[x << 1] += lazy[x];
			t[x << 1 | 1] += lazy[x];
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
			lazy[x] = 0;
		}
	}

	template<typename U>
	void update(int idx, const U &val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, const U &val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	template<typename U>
	void update(int ql, int qr, const U &val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, const U &val, int i, int l, int r) {
		if (r < ql || qr < l)
			return;
		if (ql <= l && r <= qr) {
			t[i] += val;
			lazy[i] += val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		update_helper(ql, qr, val, i << 1, l, mid);
		update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (r < ql || qr < l)
			return e;
		if (ql <= l && r <= qr)
			return t[i];
		push(i, l, r);
		int mid = (l + r) >> 1;
		T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;

	vector<pair<int, int>> more, less;
	for (int i = 0, s, a; i < n; i++) {
		cin >> s >> a;
		if (s < d) {
			continue;
		}
		if (s >= a) {
			more.emplace_back(s, a);
		} else {
			less.emplace_back(s, a);
		}
	}

	auto sort_by_finishing_time = [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
		return x.second < y.second || (x.second == y.second && x.first > y.first);
	};

	sort(more.begin(), more.end(), sort_by_finishing_time);
	sort(less.begin(), less.end(), sort_by_finishing_time);

	less.erase(remove_if(less.begin(), less.end(), [mx = int(-1)](const pair<int, int> &p) mutable {
		if (p.first <= mx) {
			return true;
		} else {
			mx = p.first;
			return false;
		}
	}), less.end());

	segment_tree<int> st(vector<int>(less.size() + 1), less.size() + 1, 0, [](int x, int y) {
		return x > y ? x : y;
	});

	int j = 0;
	for (int i = 0; i < (int) less.size(); i++) {
		while (j < (int) more.size() && more[j].second <= less[i].first) {
			int lo = 0, hi = i;
			while (lo < hi) {
				int mid = lo + (hi - lo + 1) / 2;
				if (less[mid - 1].second <= more[j].first) {
					lo = mid;
				} else {
					hi = mid - 1;
				}
			}
			st.update(0, lo, 1);
			j += 1;
		}
		int lo = 0, hi = i;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (less[mid - 1].second <= less[i].first) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		st.update(i + 1, st.query(0, lo) + 1);
	}

	while (j < (int) more.size()) {
		int lo = 0, hi = (int) less.size();
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (less[mid - 1].second <= more[j].first) {
				lo = mid;
			} else {
				hi = mid - 1;
			}
		}
		st.update(0, lo, 1);
		j += 1;
	}

	cout << st.t[1] << '\n';
	return 0;
}