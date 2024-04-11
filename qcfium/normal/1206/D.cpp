#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int64_t a[n];
	for (int i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n, std::greater<>());
	while (n && !a[n - 1]) n--;
	if (!n) {
		std::cout << -1 << std::endl;
		return 0;
	}
	
	if (n > 120) {
		std::cout << 3 << std::endl;
		return 0;
	}
	std::vector<std::set<int> > hen_(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] & a[j]) hen_[i].insert(j), hen_[j].insert(i);
		}
	}
	int res = 1000000000;
	for (int i = 0; i < n; i++) {
		auto hen = hen_;
		std::vector<int> dist(n, 1000000000);
		std::queue<int> que;
		dist[i] = 0;
		que.push(i);
		while (que.size()) {
			int cur = que.front();
			que.pop();
			for (auto j : hen[cur]) {
				int new_cost = dist[cur] + 1;
				if (dist[j] != 1000000000) {
					if (dist[j] + new_cost != 2) res = std::min(res, dist[j] + new_cost);
				}
				if (dist[j] > new_cost) {
					hen[j].erase(cur);
					dist[j] = new_cost;
					que.push(j);
				}
			}
		}
	}
	std::cout << (res == 1000000000 ? -1 : res) << std::endl;
	
	return 0;
}