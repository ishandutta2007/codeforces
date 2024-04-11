#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<long long> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const U &arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
		build(arr, 1, 0, n - 1);
	}

	template<typename U>
	void build(const U &arr, int i, int l, int r) {
		if (l == r) {
			t[i] = T(arr[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	void push(int x, int l, int r) {
		if (lazy[x]) {
			int mid = (l + r) >> 1;
			t[x << 1] += (mid - l + 1) * lazy[x];
			t[x << 1 | 1] += (r - mid) * lazy[x];
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
			lazy[x] = 0;
		}
	}

	template<typename U>
	void update(int ql, int qr, U val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, U val, int i, int l, int r) {
		if (r < ql || qr < l)
			return;
		if (ql <= l && r <= qr) {
			t[i] += (long long)(r - l + 1) * val;
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

	int n, m;
	cin >> n >> m;

	segment_tree<long long> st(vector<int>(n), n, 0, [&](auto x, auto y) {
		return x + y;
	});

	map<int, int> mp; mp[-1], mp[n];
	for (int i = 0; i < n; i++) {
		mp[i] = i + 1;
	}

	while (m--) {
		int t;
		cin >> t;

		if (t == 1) {
			int l, r, y;
			cin >> l >> r >> y, --l, --r;
			auto it1 = prev(mp.upper_bound(l)), it2 = next(it1);
			if (it1->first <= l && r < it2->first) {
				st.update(l, r, abs(y - it1->second));
				if (r + 1 != it2->first) {
					mp[r + 1] = it1->second;
				}
			} else {
				while (true) {
					if (l <= it1->first && it2->first <= r) {
						st.update(it1->first, it2->first - 1, abs(y - it1->second));
						it1 = mp.erase(it1), it2 = next(it1);
					} else if (it1->first <= l) {
						st.update(l, it2->first - 1, abs(y - it1->second));
						it1++, it2++;
					} else if (it2->first > r) {
						st.update(it1->first, r, abs(y - it1->second));
						int x = it1->second;
						mp.erase(it1);
						if (r + 1 != it2->first) {
							mp[r + 1] = x;
						}
						break;
					}
				}
			}
			mp[l] = y;
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.query(--l, --r) << '\n';
		}
	}
	return 0;
}