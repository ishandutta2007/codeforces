#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int get_root(vector<int>& root, int p) {
	int r = p;
	while (root[r] != r) {
		r = root[r];
	}
	while (p != r) {
		int next = root[p];
		root[p] = r;
		p = next;
	}
	return r;
}

void one_case(int n) {
	int m;
	long long delta;
	cin >> m >> delta;
	vector<long long> a(n);
	long long sum_a = 0;
	for (int i = 0; i < n; ++i) {
		int a0;
		cin >> a0;
		a[i] = a0;
		sum_a += a0;
	}
	if (sum_a < delta * (n - 1)) {
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
		}
		printf("NO\n");
		return;
	}
	vector<int> root(n + n);
	vector<int> node1(n + n);
	vector<int> node2(n + n);
	vector<int> edge_id(n + n);
	vector<int> edge_x(n + n);
	vector<int> edge_y(n + n);
	vector<int> count(n + n);
	for (int i = 0; i < n + n; ++i) {
		root[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		count[i] = 1;
	}
	int next_id = n;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		int rx = get_root(root, x);
		int ry = get_root(root, y);
		if (rx == ry) {
			continue;
		}
		int id = (next_id++);
		root[rx] = id;
		root[ry] = id;
		node1[id] = rx;
		node2[id] = ry;
		edge_id[id] = i;
		edge_x[id] = x;
		edge_y[id] = y;
		count[id] = count[rx] + count[ry];
	}

	vector<int> order;
	vector<int> s_order(n + n);
	vector<int> t_order(n + n);
	std::function<void(int)> dfs1 = [&](int current) {
		s_order[current] = order.size();
		if (current < n) {
			order.push_back(current);
		} else {
			dfs1(node1[current]);
			dfs1(node2[current]);
		}
		t_order[current] = order.size();
	};
	dfs1(next_id - 1);
	vector<int> dfn(n);
	for (int i = 0; i < n; ++i) {
		dfn[order[i]] = i;
	}
	vector<long long> sum(n + 1);

	auto change_sum = [&](int i, long long delta) {
		for (; i <= n; i += (i & (-i))) {
			sum[i] += delta;
		}
	};
	auto get_sum = [&](int i) -> long long {
		long long result = 0;
		for (; i > 0; i -= (i & (-i))) {
			result += sum[i];
		}
		return result;
	};

	for (int i = 0; i < n; ++i) {
		change_sum(dfn[i] + 1, a[i]);
	}

	vector<int> result;

	std::function<long long(int)> dfs = [&](int current) -> long long {
		if (current < n) {
			return a[current];
		}
		int rx = node1[current];
		int ry = node2[current];
		int px = edge_x[current];
		int py = edge_y[current];
		long long mx = get_sum(t_order[rx]) - get_sum(s_order[rx]) - delta * (count[rx] - 1);
		long long my = get_sum(t_order[ry]) - get_sum(s_order[ry]) - delta * (count[ry] - 1);
		if (mx < my) {
			swap(mx, my);
			swap(rx, ry);
			swap(px, py);
		}
		if (mx >= 0 && my >= 0) {
			long long ret = dfs(rx) + dfs(ry);
			assert(ret >= delta);
			ret -= delta;
			result.push_back(edge_id[current]);
			return ret;
		}
		long long left_x = dfs(rx);
		result.push_back(edge_id[current]);
		assert(a[py] + left_x >= delta);
		a[py] += left_x - delta;
		change_sum(dfn[py] + 1, left_x - delta);
		return dfs(ry);
	};

	dfs(next_id - 1);
	
	assert(result.size() == n - 1);
	printf("YES\n");
	for (int idx : result) {
		printf("%d\n", idx + 1);
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		one_case(n);
	}
	return 0;
}