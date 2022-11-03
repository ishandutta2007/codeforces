#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

std::random_device rnd_dev;
std::mt19937 rnd(rnd_dev() ^ clock());
int range(int l, int r) {
	return l + std::uniform_int_distribution<>(0, r - l)(rnd);
}

void solve() {
	int n = ri();
	int x = ri();
	int y = ri();
	std::vector<int> a(n);
	for (auto &i : a) i = ri() - 1;
	
	/*
	std::cerr << n << " " << x << " " << y << std::endl;
	for (auto i : a) std::cerr << i << " ";
	std::cerr << std::endl;*/
	
	int used[n + 1];
	memset(used, 0, sizeof(used));
	for (auto i : a) used[i]++;
	int unused = std::find(used, used + n + 1, 0) - used;
	// int mostused = std::max_element(used, used + n + 1) - used;
	
	std::vector<int> index[n + 1];
	for (int i = 0; i < n; i++) index[a[i]].push_back(i);
	std::priority_queue<std::pair<int, int> > que;
	for (int i = 0; i <= n; i++) que.push({used[i], i});
	int res[n];
	std::vector<bool> solid(n);
	for (int i = 0; i < x; i++) {
		auto j = que.top();
		que.pop();
		que.push({j.first - 1, j.second});
		used[j.second]--;
		int t = index[j.second].back();
		index[j.second].pop_back();
		res[t] = a[t];
		solid[t] = true;
	}
	int space = n - x;
	std::vector<bool> choose(n);
	int left = y - x;
	int max = 0;
	for (int i = 0; i <= n; i++) {
		int usable = std::min({left, used[i], space - used[i]});
		max = std::max(max, used[i]);
		left -= usable;
		for (int j = 0; j < usable; j++) choose[index[i][j]] = true;
	}
	if (left) {
		puts("NO");
		return;
	}
	std::vector<std::pair<int, int> > free;
	for (int i = 0; i < n; i++) if (!solid[i]) free.push_back({i, choose[i]});
	
	std::sort(free.begin(), free.end(), [&] (auto i, auto j) {
		if (a[i.first] != a[j.first]) return a[i.first] < a[j.first];
		return i.second < j.second;
	});
	auto free_org = free;
	
	/*
	for (auto i : free) std::cerr << i.first << "," << i.second << "  ";
	std::cerr << std::endl;*/
	std::rotate(free.begin(), free.begin() + max, free.end());
	/*
	for (auto i : free) std::cerr << i.first << "," << i.second << "  ";
	std::cerr << std::endl;*/
	for (int i = 0; i < (int) free.size(); i++) {
		if (free[i].second) res[free_org[i].first] = a[free[i].first], assert(a[free_org[i].first] != a[free[i].first]); // use
		else res[free_org[i].first] = unused; // spoil
	}
	
	puts("YES");
	for (auto i : res) printf("%d ", i + 1);
	puts("");
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) solve();
	return 0;
}