#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

#define LINF 1000000000000000000

std::vector<int> a, h;
std::vector<std::vector<int> > hen;

std::vector<int64_t> dp0; // down
std::vector<int64_t> dp1; // up

int64_t res;

void dfs(int i, int prev) {
	if (prev != -1) hen[i].erase(std::find(hen[i].begin(), hen[i].end(), prev));
	for (auto j : hen[i]) dfs(j, i);
	
	int m = hen[i].size();
	int64_t base = 0;
	int balance = 0;
	std::vector<int64_t> diffs;
	for (auto j : hen[i]) {
		if (h[j] > h[i]) balance++, base += dp0[j]; // down only
		else if (h[j] < h[i]) balance--, base += dp1[j]; // up only
		else balance++, base += dp0[j], diffs.push_back(dp1[j] - dp0[j]); // tentatively down
	}
	std::sort(diffs.begin(), diffs.end(), std::greater<>());
	
	auto add_cost = [&] () {
		return (int64_t) (m + std::abs(balance)) / 2 * a[i];
	};
	
	int64_t tmp[3];
	while (balance - 2 > 0 && diffs.size() && diffs.back() <= a[i]) {
		base += diffs.back();
		diffs.pop_back();
		balance -= 2;
	}
	if (balance > 0) tmp[0] = base + add_cost();
	else tmp[0] = LINF;
	while (balance - 2 >= 0 && diffs.size()) {
		base += diffs.back();
		diffs.pop_back();
		balance -= 2;
	}
	if (!balance) tmp[1] = base + add_cost();
	else tmp[1] = LINF;
	while (balance - 2 >= -2 && diffs.size()) {
		base += diffs.back();
		diffs.pop_back();
		balance -= 2;
	}
	while (diffs.size() && diffs.back() <= -a[i]) {
		base += diffs.back();
		diffs.pop_back();
		balance -= 2;
	}
	if (balance < 0) tmp[2] = base + add_cost();
	else tmp[2] = LINF;
	
	dp0[i] = std::min({tmp[0], tmp[1] + a[i], tmp[2] + a[i]});
	dp1[i] = std::min({tmp[0] + a[i], tmp[1] + a[i], tmp[2]});
	if (i == 0) res = std::min({tmp[0], tmp[1], tmp[2]});
}

int main() {
	int n = ri();
	a.resize(n);
	for (auto &i : a) i = ri();
	h.resize(n);
	for (auto &i : h) i = ri();
	
	hen.resize(n);
	for (int i = 1; i < n; i++) {
		int a = ri() - 1;
		int b = ri() - 1;
		hen[a].push_back(b);
		hen[b].push_back(a);
	}
	
	dp0.resize(n, LINF);
	dp1.resize(n, LINF);
	dfs(0, -1);
	printf("%" PRId64 "\n", res);
	return 0;
}