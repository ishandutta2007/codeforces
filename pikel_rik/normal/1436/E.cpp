#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

template<typename T>
class SegmentTree {
public:
	using F = function<T(const T &, const T &)>;

	int n;
	vector<T> t;
	T e;
	F f;

	SegmentTree() : n(), e(), f() {}

	template<typename U>
	SegmentTree(const U &arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
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

	template<typename U>
	void update(int idx, U val) {
		updateHelper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void updateHelper(int idx, U val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			updateHelper(idx, val, i << 1, l, mid);
		else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int l) {
		return queryHelper(l, 1, 0, n - 1);
	}

	T queryHelper(int ql, int i, int l, int r) {
		if (l == r) {
			return l;
		}
		int mid = (l + r) >> 1;
		if (t[i << 1] >= ql) {
			return queryHelper(ql, i << 1 | 1, mid + 1, r);
		} else {
			return queryHelper(ql, i << 1, l, mid);
		}
	}
};

int n, a[N];
vector<int> pos[N];

int q, ans[2 * N];
vector<pair<int, int>> queries[N];

void addQuery(int l, int r) {
	queries[r].emplace_back(l, q++);
}

void processQueries() {
	SegmentTree<int> st(vector<int>(n + 1, -1), n + 1, -1, [&] (int x, int y) {
		return x < y ? x : y;
	});

	for (int r = 0; r < n; r++) {
		st.update(a[r], r);
		for (auto& [l, i] : queries[r]) {
			ans[i] = st.query(l);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], --a[i];

	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i);
	}
	for (int i = 0; i <= n; i++) {
		pos[i].push_back(n);
	}

	for (int i = 0; i <= n; i++) {
		if (pos[i].front() != 0) {
			addQuery(0, pos[i].front() - 1);
		}
		for (int j = 1; j < pos[i].size(); j++) {
			if (pos[i][j] != pos[i][j - 1] + 1) {
				addQuery(pos[i][j - 1] + 1, pos[i][j] - 1);
			}
		}
	}

	processQueries();

	for (int i = 0, id = 0; i <= n; i++) {
		bool there = false;
		if (pos[i].front() != 0) {
			there |= ans[id++] == i;
		}
		for (int j = 1; j < pos[i].size(); j++) {
			if (pos[i][j] != pos[i][j - 1] + 1) {
				there |= ans[id++] == i;
			}
		}

		if (!there) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	cout << n + 2 << '\n';
	return 0;
}