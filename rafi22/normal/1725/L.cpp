// Olaf Surgut 17.09.2022 10:29:31
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	
	#define int int64_t

	int n; cin >> n;

	vector<int> a(n);
	
	for (int &x : a) {
		cin >> x;
	}

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}

	if (*min_element(a.begin(), a.end()) < 0 ||
		a[n - 1] < *max_element(a.begin(), a.end() - 1)) {
		cout << "-1\n";
		return 0;
	}

	vector<int> b = a;

	sort(b.begin(), b.end());

	b.erase(unique(b.begin(), b.end()), b.end());

	int tree_size = 1;

	while (tree_size < (int) b.size())
		tree_size <<= 1;

	vector<int> tree(tree_size << 1);

	auto update = [&](int pos, int val) {
		for (tree[pos += tree_size] += val; pos >>= 1; ) {
			tree[pos] = tree[pos << 1 | 0] + tree[pos << 1 | 1];
		}
	};

	auto query = [&](int l, int r) {
		int res = 0;
		for (l += tree_size, r += tree_size + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1)	res += tree[l++];
			if (r & 1)	res += tree[--r];
		}
		return res;
	};

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int id = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());

		ans += query(id + 1, tree_size - 1);

		update(id, +1);
	}

	cout << ans << '\n';
}