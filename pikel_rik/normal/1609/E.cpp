#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
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

	template<typename U>
	void update(int idx, U val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, U val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (qr < l || r < ql)
			return e;
		if (ql <= l && r <= qr)
			return t[i];
		int mid = (l + r) >> 1;
		T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	for (auto &ch : s) {
		ch -= 'a';
	}

	constexpr int inf = (int) 1e9;

	struct node {
		array<int, 3> cnt = {};
		int skipped_a = inf, skipped_b = inf, skipped_c = inf, skipped_ac = inf;

		node() { }

		node (int c) {
			cnt[c] += 1;
			skipped_a = skipped_c = 1;
			skipped_b = 0;
			if (c == 0) {
				skipped_a = 0;
			} else if (c == 2) {
				skipped_c = 0;
			}
		}
	};

	segment_tree<node> st(vector<int>(s.begin(), s.end()), n, node(), [](const node &x, const node &y) {
		node result;
		for (int c = 0; c < 3; c++) {
			result.cnt[c] = x.cnt[c] + y.cnt[c];
		}
		result.skipped_a = min({inf, x.skipped_a + y.cnt[1], x.cnt[0] + y.skipped_a});
		result.skipped_b = min({inf, x.skipped_b + y.cnt[2], x.cnt[0] + y.skipped_b});
		result.skipped_c = min({inf, x.skipped_c + y.cnt[2], x.cnt[1] + y.skipped_c});
		result.skipped_ac = min({inf, x.skipped_a + y.skipped_c, x.skipped_ac + y.cnt[2], x.cnt[0] + y.skipped_ac});
		return result;
	});

	while (q--) {
		int i; char c;
		cin >> i >> c, --i;

		c -= 'a';

		if (s[i] != c) {
			st.update(i, c);
			s[i] = c;
		}

		int ans = min(st.t[1].skipped_b, st.t[1].skipped_ac);
		ans = min({ans, st.t[1].cnt[0], st.t[1].cnt[1], st.t[1].cnt[2]});
		cout << ans << '\n';
	}
	return 0;
}