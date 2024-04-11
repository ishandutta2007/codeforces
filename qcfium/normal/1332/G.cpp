#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int q = ri();
	int a[n];
	for (auto &i : a) i = ri();
	
	// strict
	int down[n];
	int up[n];
	{
		std::vector<int> descending;
		std::vector<int> climbing;
		for (int i = n - 1; i >= 0; i--) {
			auto itr0 = std::lower_bound(descending.begin(), descending.end(), a[i], [&] (int i, int j) { return a[i] < j; });
			if (itr0 == descending.begin()) down[i] = n;
			else down[i] = *std::prev(itr0);
			auto itr1 = std::lower_bound(climbing.begin(), climbing.end(), a[i], [&] (int i, int j) { return a[i] > j; });
			if (itr1 == climbing.begin()) up[i] = n;
			else up[i] = *std::prev(itr1);
			while (descending.size() && a[descending.back()] >= a[i]) descending.pop_back();
			while (climbing.size() && a[climbing.back()] <= a[i]) climbing.pop_back();
			descending.push_back(i);
			climbing.push_back(i);
		}
	}
	
	std::set<int> downings;
	for (int i = 0; i + 1 < n; i++) if (a[i + 1] < a[i]) downings.insert(i);
	std::set<int> uppings;
	for (int i = 0; i + 1 < n; i++) if (a[i + 1] > a[i]) uppings.insert(i);
	
	// 3
	std::vector<std::vector<int> > all3;
	for (int i = 0; i < n; i++) {
		std::vector<int> r0;
		if (up[i] != n) {
			auto itr = downings.lower_bound(up[i]);
			if (itr != downings.end()) {
				while (all3.size() && all3.back().back() >= *itr + 1) all3.pop_back();
				all3.push_back({i, *itr, *itr + 1});
			}
		}
		if (down[i] != n) {
			auto itr = uppings.lower_bound(down[i]);
			if (itr != uppings.end()) {
				while (all3.size() && all3.back().back() >= *itr + 1) all3.pop_back();
				all3.push_back({i, *itr, *itr + 1});
			}
		}
	}
	// 4
	int down2[20][n];
	int up2[20][n];
	{
		std::vector<int> descending;
		std::vector<int> climbing;
		for (int i = n - 1; i >= 0; i--) {
			auto itr0 = std::lower_bound(descending.begin(), descending.end(), a[i], [&] (int i, int j) { return a[i] <= j; });
			down2[0][i] = itr0 == descending.begin() ? n : *std::prev(itr0);
			auto itr1 = std::lower_bound(climbing.begin(), climbing.end(), a[i], [&] (int i, int j) { return a[i] >= j; });
			up2[0][i] = itr1 == climbing.begin() ? n : *std::prev(itr1);
			while (descending.size() && a[descending.back()] >= a[i]) descending.pop_back();
			while (climbing.size() && a[climbing.back()] <= a[i]) climbing.pop_back();
			descending.push_back(i);
			climbing.push_back(i);
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < n; j++) {
			down2[i][j] = down2[i - 1][j] == n ? n : down2[i - 1][down2[i - 1][j]];
			up2[i][j] = up2[i - 1][j] == n ? n : up2[i - 1][up2[i - 1][j]];
		}
	}
	std::vector<std::vector<int> > all4;
	for (int i = 0; i < n; i++) {
		if (down[i] == n || up[i] == n) continue;
		int r0 = down[i];
		int r1 = up[i];
		for (int j = 20; j--; ) {
			if (down2[j][r0] < r1) r0 = down2[j][r0];
			if (up2[j][r1] < r0) r1 = up2[j][r1];
		}
		int l = std::max(r0, r1);
		int r = n;
		while (r - l > 1) {
			int m = l + ((r - l) >> 1);
			int r00 = r0, r11 = r1;
			int needed = m - std::max(r0, r1);
			int real = 0;
			for (int j = 20; j--; ) {
				if (down2[j][r00] <= m) real += 1 << j, r00 = down2[j][r00];
				if (up2[j][r11] <= m) real += 1 << j, r11 = up2[j][r11];
			}
			if (needed == real) l = m;
			else r = m;
		}
		if (r == n) continue;
		for (int j = 20; j--; ) {
			if (down2[j][r0] <= r) r0 = down2[j][r0];
			if (up2[j][r1] <= r) r1 = up2[j][r1];
		}
		while (all4.size() && all4.back().back() >= r) all4.pop_back();
		all4.push_back({i, std::min(r0, r1), std::max(r0, r1), r});
	}
	/*
	for (auto i : all3) {
		for (auto j : i) std::cerr << j << " ";
		std::cerr << std::endl;
	}
	std::cerr << std::endl;
	for (auto i : all4) {
		for (auto j : i) std::cerr << j << " ";
		std::cerr << std::endl;
	}*/
	for (int i = 0; i < q; i++) {
		int l = ri() - 1;
		int r = ri();
		std::vector<int> res;
		auto itr3 = std::lower_bound(all3.begin(), all3.end(), l, [] (auto i, int j) { return i.front() < j; });
		auto itr4 = std::lower_bound(all4.begin(), all4.end(), l, [] (auto i, int j) { return i.front() < j; });
		if (itr3 != all3.end() && itr3->back() < r) res = *itr3;
		if (itr4 != all4.end() && itr4->back() < r) res = *itr4;
		printf("%d\n", (int) res.size());
		for (auto i : res) printf("%d ", i + 1);
		puts("");
	}
	
	
	return 0;
}