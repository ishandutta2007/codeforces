#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

void solve() {
	int n = ri();
	std::string s, t;
	std::cin >> s >> t;
	for (auto &i : s) i -= '0';
	for (auto &i : t) i -= '0';
	std::deque<bool> all;
	for (auto &i : s) all.push_back(i);
	bool flipped = false;
	auto back = [&] () { return flipped ? !all.front() : all.back(); };
	auto front = [&] () { return flipped ? !all.back() : all.front(); };
	std::vector<int> res;
	for (int i = n; i--; ) {
		if (back() != t[i]) {
			if (front() == t[i]) { // fix
				res.push_back(1);
				(flipped ? all.back() : all.front()) ^= 1;
			}
			res.push_back(all.size());
			flipped ^= 1;
		}
		if (flipped) all.pop_front();
		else all.pop_back();
	}
	printf("%d", (int) res.size());
	for (auto i : res) printf(" %d", i);
	puts("");
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) solve();
	return 0;
}