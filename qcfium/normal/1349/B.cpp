#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

bool solve_sub(const std::vector<bool> a) {
	int n = a.size();
	
	int min = 1000000000;
	int cur = 0;
	for (auto i : a) {
		int next = i ? cur + 1 : cur - 1;
		if (min < next) return true;
		min = std::min(min, cur);
		cur = next;
	}
	return false;
}

bool solve() {
	int n = ri();
	int k = ri();
	int a[n];
	for (auto &i : a) i = ri();
	
	for (int i = 0; i + 1 < n; i++) if (a[i] == k && a[i + 1] == k) return true;
	if (!std::count(a, a + n, k)) return false;
	if (n == 1) return true;
	
	std::vector<bool> all(n);
	for (int i = 0; i < n; i++) all[i] = a[i] >= k;
	return solve_sub(all);
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) puts(solve() ? "yes" : "no");
	
	return 0;
}