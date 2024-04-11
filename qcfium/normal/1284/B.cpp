#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	std::vector<int> a[n];
	for (auto &i : a) {
		i.resize(ri());
		for (auto &j : i) j = ri();
	}
	int64_t res = (int64_t) n * n;
	std::vector<int> heads;
	for (int i = 0; i < n; i++) if (std::is_sorted(a[i].begin(), a[i].end(), std::greater<>())) heads.push_back(a[i][0]);
	std::sort(heads.begin(), heads.end());
	int head = 0;
	std::sort(a, a + n, [] (auto &i, auto &j) { return i.back() < j.back(); });
	for (int i = 0; i < n; i++) {
		if (!std::is_sorted(a[i].begin(), a[i].end(), std::greater<>())) continue;
		while (head < (int) heads.size() && heads[head] <= a[i].back()) head++;
		res -= head;
	}
	std::cout << res << std::endl;
	return 0;
}