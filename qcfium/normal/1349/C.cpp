#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
struct UnionFind {
	std::vector<int> data;
	std::vector<int> res;
	UnionFind (int size) : data(size, -1), res(size) {}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x != y) {
			data[x] += data[y];
			data[y] = x;
		}
		return x != y;
	}
	int info(int x) { return res[root(x)]; }
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	bool connected() { return size(0) == (int) data.size(); }
};

std::pair<int, int> dd[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

#define INDEX(x, y) ((x) * w + (y))
int main() {
	int h = ri();
	int w = ri();
	int q = ri();
	std::string s[h];
	for (auto &i : s) std::cin >> i;
	struct Query {
		int x;
		int y;
		int64_t p;
		int id;
	};
	Query qs[q];
	for (int i = 0; i < q; i++) {
		qs[i].x = ri() - 1;
		qs[i].y = ri() - 1;
		scanf("%" SCNd64, &qs[i].p);
		qs[i].id = i;
	}
	std::sort(qs, qs + q, [] (auto &i, auto &j) { return i.p < j.p; });
	int res[q];
	UnionFind uni(h * w);
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
		uni.res[INDEX(i, j)] = s[i][j] == '1';
		for (auto d : dd) {
			int x = i + d.first;
			int y = j + d.second;
			if (x < 0 || x >= h || y < 0 || y >= w) continue;
			if (s[i][j] == s[x][y]) uni.unite(INDEX(i, j), INDEX(x, y));
		}
	}
	std::vector<std::pair<int, int> > que;
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
		if (uni.size(INDEX(i, j)) > 1) que.push_back({i, j});
	
	auto query = [&] (int x, int y, int time) -> int {
		if (uni.size(INDEX(x, y)) == 1) return s[x][y] == '1';
		return (time ^ uni.info(INDEX(x, y))) & 1;
	};
	int head = 0;
	for (int i = 1; ; i++) {
		std::vector<std::pair<int, int> > next;
		for (auto j : que) {
			for (auto k : dd) {
				int x = j.first + k.first;
				int y = j.second + k.second;
				if (x < 0 || x >= h || y < 0 || y >= w) continue;
				if (uni.size(INDEX(x, y)) == 1) {
					next.push_back({x, y});
					uni.unite(INDEX(j.first, j.second), INDEX(x, y));
				}
			}
		}
		que = next;
		while (head < q && qs[head].p == i) {
			res[qs[head].id] = query(qs[head].x, qs[head].y, i);
			head++;
		}
		if (!next.size()) break;
	}
	for (; head < q; head++) res[qs[head].id] = query(qs[head].x, qs[head].y, qs[head].p & 1);
	for (auto i : res) printf("%d\n", i);
	return 0;
}