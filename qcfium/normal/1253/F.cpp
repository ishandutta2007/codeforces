#include <bits/stdc++.h>

#ifdef WIN32
#define getchar_fast _getchar_nolock
#else
#define getchar_fast getchar_unlocked
#endif
int ri() {
	int r = 0, c, s = 0;
	for (;;) {
		c = getchar();
		if (c == '-') {
			s = 1;
			break;
		}
		if (c >= '0' && c <= '9') {
			r = c - '0';
			break;
		}
	}
	for (;;) {
		c = getchar();
		if (c < '0' || c > '9') break;
		r = r * 10 + c - '0';
	}
	return s ? -r : r;
}
struct UnionFind {
	std::vector<int> data;
	UnionFind (int size) : data(size, -1) {}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x != y) {
			if (data[y] < data[x]) std::swap(x, y);
			data[x] += data[y];
			data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	bool connected() { return size(0) == (int) data.size(); }
};

int main() {
	int n = ri(), m = ri(), k = ri(), q = ri();
	std::vector<std::pair<int, int64_t> > hen[n];
	struct Hen {
		int x;
		int y;
		int64_t cost;
	};
	std::vector<Hen> hens(m);
	for (int i = 0; i < m; i++) {
		int x = ri() - 1;
		int y = ri() - 1;
		int c = ri();
		hen[x].push_back({y, c});
		hen[y].push_back({x, c});
		hens[i] = {x, y, c};
	}
	using T = std::pair<int64_t, int>;
	std::vector<int64_t> dist(n, 1000000000000000000);
	std::priority_queue<T, std::vector<T>, std::greater<T> > que;
	for (int i = 0; i < k; i++) que.push({0, i}), dist[i] = 0;
	while (que.size()) {
		auto cur = que.top();
		que.pop();
		if (cur.first != dist[cur.second]) continue;
		for (auto j : hen[cur.second]) {
			if (dist[j.first] > cur.first + j.second) {
				dist[j.first] = cur.first + j.second;
				que.push({dist[j.first], j.first});
			}
		}
	}
	for (auto &i : hens) i.cost += dist[i.x] + dist[i.y];
	std::sort(hens.begin(), hens.end(), [] (auto i, auto j) { return i.cost < j.cost; });
	{
		std::vector<Hen> tmp;
		UnionFind uni(n);
		for (auto i : hens) if (uni.unite(i.x, i.y)) tmp.push_back(i);
		std::swap(tmp, hens);
	}
	for (auto &i : hen) i.clear();
	for (auto i : hens) hen[i.x].push_back({i.y, i.cost}), hen[i.y].push_back({i.x, i.cost});
	std::vector<int> depth(n);
	std::vector<std::vector<std::pair<int, int64_t> > > parent(n, std::vector<std::pair<int, int64_t> > (20, {-1, -1}));
	std::function<void(int, int)> dfs = [&] (int i, int prev) {
		for (auto j : hen[i]) {
			if (j.first == prev) continue;
			depth[j.first] = depth[i] + 1;
			parent[j.first][0] = {i, j.second};
			dfs(j.first, i);
		}
	};
	dfs(0, -1);
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < n; j++) {
			if (parent[j][i - 1].first == -1) parent[j][i] = {-1, -1};
			else {
				parent[j][i] = parent[parent[j][i - 1].first][i - 1];
				parent[j][i].second = std::max(parent[j][i].second, parent[j][i - 1].second);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int x = ri() - 1;
		int y = ri() - 1;
		int64_t res = 0;
		if (depth[x] < depth[y]) std::swap(x, y);
		for (int k = 20; k--; ) if ((depth[x] - depth[y]) >> k & 1) res = std::max(res, parent[x][k].second), x = parent[x][k].first;
		if (x != y) {
			for (int k = 20; k--; ) if (parent[x][k].first != parent[y][k].first)
				res = std::max({res, parent[x][k].second, parent[y][k].second}), x = parent[x][k].first, y = parent[y][k].first;
			res = std::max({res, parent[x][0].second, parent[y][0].second});
		}
		printf("%lld\n", (long long) res);
	}
	return 0;
}