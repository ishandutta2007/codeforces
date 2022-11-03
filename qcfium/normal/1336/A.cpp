#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

std::vector<std::vector<int> > hen;
std::vector<int> all;
std::vector<int> size;
std::vector<int> depth;

void dfs(int i, int prev) {
	bool has_child = false;
	for (auto j : hen[i]) if (j != prev) {
		has_child = true;
		depth[j] = depth[i] + 1;
		dfs(j, i);
		size[i] += size[j];
	}
	all.push_back(depth[i] - size[i] + 1);
}

int main() {
	int n = ri();
	int k = ri();
	hen.resize(n);
	for (int i = 1; i < n; i++) {
		int a = ri() - 1;
		int b = ri() - 1;
		hen[a].push_back(b);
		hen[b].push_back(a);
	}
	size.resize(n, 1);
	depth.resize(n);
	dfs(0, -1);
	std::sort(all.begin(), all.end(), std::greater<>());
	printf("%lld\n", std::accumulate(all.begin(), all.begin() + k, 0LL));
	return 0;
}