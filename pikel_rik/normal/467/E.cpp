#include <bits/stdc++.h>
using namespace std;

struct merge_sort_tree {
	using node = std::vector<int>;

	int n;
	std::vector<node> t;

	merge_sort_tree() : n() {}

	template<typename U>
	merge_sort_tree(const U &arr, int n): n(n), t(4 * n) {
		build(arr, 1, 0, n - 1);
	}

	template<typename U>
	void build(const U &arr, int i, int l, int r) {
		if (l == r) {
			t[i] = {arr[l]};
			return;
		}
		int mid = (l + r) >> 1;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);
		t[i].resize(t[i << 1].size() + t[i << 1 | 1].size());
		merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(), t[i << 1 | 1].end(), t[i].begin());
	}

	int query(int ql, int qr, int x) {
		return query_helper(ql, qr, x, 1, 0, n - 1);
	}

	int query_helper(int ql, int qr, int x, int i, int l, int r) {
		if (r < ql || qr < l)
			return n;
		if (ql <= l && r <= qr) {
			auto it = lower_bound(t[i].begin(), t[i].end(), x);
			return it != t[i].end() ? *it : n;
		}
		int mid = (l + r) >> 1;
		return min(query_helper(ql, qr, x, i << 1, l, mid), query_helper(ql, qr, x, i << 1 | 1, mid + 1, r));
	}
};

vector<int> compress(vector<int> &a) {
	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (auto &x : a) x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	auto temp = compress(a);

	int sz = temp.size();
	vector<vector<int>> pos(sz);

	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i);
	}

	vector<int> next(n, n), r(n, n);
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j + 1 < pos[i].size(); j++) {
			next[pos[i][j]] = pos[i][j + 1];
		}
	}

	merge_sort_tree st(next, n);

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j + 1 < pos[i].size(); j++) {
			if (pos[i][j] + 1 != pos[i][j + 1]) {
				r[pos[i][j]] = st.query(pos[i][j] + 1, pos[i][j + 1] - 1, pos[i][j + 1] + 1);
			}
		}
		for (int j = 0; j + 3 < pos[i].size(); j++) {
			r[pos[i][j]] = min(r[pos[i][j]], pos[i][j + 3]);
		}
	}

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return r[i] < r[j];
	});

	int last = -1;
	vector<int> ans;

	for (int i : ind) {
		if (r[i] != n && last < i) {
			ans.push_back(i);
			last = r[i];
		}
	}

	cout << 4 * ans.size() << '\n';
	for (int i : ans) {
		cout << temp[a[i]] << ' ' << temp[a[r[i]]] << ' ' << temp[a[i]] << ' ' << temp[a[r[i]]] << ' ';
	}
	cout << '\n';
	return 0;
}