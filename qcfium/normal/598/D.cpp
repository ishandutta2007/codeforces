#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

const std::pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	int h = ri();
	int w = ri();
	int q = ri();
	std::string a[h];
	for (auto &i : a) std::cin >> i;
	
	std::vector<int> list[h][w];
	int head = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i + 1 < h && a[i][j] != a[i + 1][j]) list[i][j].push_back(head), list[i + 1][j].push_back(head), head++;
			if (j + 1 < w && a[i][j] != a[i][j + 1]) list[i][j].push_back(head), list[i][j + 1].push_back(head), head++;
		}
	}
	int res[h][w];
	for (auto &i : res) for (auto &j : i) j = -1;
	for (int i = 0; i < q; i++) {
		int x = ri() - 1;
		int y = ri() - 1;
		if (res[x][y] == -1) {
			std::queue<std::pair<int, int> > que;
			que.push({x, y});
			std::vector<std::pair<int, int> > all;
			std::set<int> pics;
			while (que.size()) {
				auto i = que.front();
				que.pop();
				all.push_back(i);
				for (auto j : list[i.first][i.second]) pics.insert(j);
				for (auto d : dirs) {
					int x = i.first + d.first;
					int y = i.second + d.second;
					if (x < 0 || x >= h || y < 0 || y >= w) continue;
					if (a[x][y] == '*' || res[x][y] != -1) continue;
					res[x][y] = 0;
					que.push({x, y});
				}
			}
			for (auto j : all) res[j.first][j.second] = pics.size();
		}
		printf("%d\n", res[x][y]);
	}
	
	return 0;
}