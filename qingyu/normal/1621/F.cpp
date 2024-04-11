#include <bits/stdc++.h>

long long solve(int parity, auto corner, auto middle, int p0, int p1, int l0, int fl0, int a, int b, int c) {
	long long ans = 0, cur = 0;
	auto pop_middle = [&]() {
		assert(!middle.empty());
		--middle.back();
		if (middle.back() == 1) {
			middle.pop_back();
			++l0;
		}
	};
	auto pop_corner = [&]() {
		assert(!corner.empty());
		--corner.back();
		if (corner.back() == 1) {
			corner.pop_back();
			++fl0;
		}
	};
	for (int i = parity; ; i ^= 1) {
		if (i == 0) {
			if (!p1) {
				break;
			}
			else {
				--p1;
				cur += b;
			}
		}
		else {
			if (p0) {
				if (p1 || !l0) {
					--p0;
					if (!middle.empty()) {
						pop_middle();
					}
					else if (!corner.empty()) {
						pop_corner();
					}
					else throw;
					cur += a;
				}
				else {
					ans = std::max(ans, cur + a);
					--l0;
					++p1;
					cur -= c;
				}
			}
			else {
				if (l0) {
					--l0;
					cur -= c;
					++p1;
				}
				else if (fl0) {
					--fl0;
					cur -= c;
				}
				else {
					break;
				}
			}
		}
		ans = std::max(ans, cur);
	}
	return ans;
}

long long solve() {
	int n, a, b, c;
	std::string s;
	std::cin >> n >> a >> b >> c >> s;
	std::vector<int> buc(n);
	std::vector<int> corner, middle;
	int p0 = 0, p1 = 0, l0 = 0, fl0 = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] == '0' && s[i + 1] == '0') {
			++p0;
		}
		if (s[i] == '1' && s[i + 1] == '1') {
			++p1;
		}
	}
	if (s[0] == '0' && !buc[0]) {
		int j = 0, cnt = 0;
		while (j < n && s[j] == '0') {
			buc[j] = true;
			++j;
			++cnt;
		}
		if (cnt == 1) ++fl0;
		else corner.emplace_back(j);
	}
	if (s[n - 1] == '0' && !buc[n - 1]) {
		int j = n - 1, cnt = 0;
		while (j >= 0 && s[j] == '0' && !buc[j]) {
			buc[j] = true;
			--j;
			++cnt;
		}
		if (cnt == 1) ++fl0;
		else corner.emplace_back(n - j - 1);
	}
	int current = 0;
	for (int i = 0; i < n; ++i) {
		if (buc[i]) continue;
		if (s[i] == '0') {
			++current;
		}
		else {
			if (current > 1) middle.emplace_back(current);
			else if (current == 1) ++l0;
			current = 0;
		}
	}
	if (current > 1) middle.emplace_back(current);
	else if (current == 1) ++l0;
	std::sort(corner.begin(), corner.end(), std::greater<int>());
	std::sort(middle.begin(), middle.end(), std::greater<int>());
	return std::max(solve(0, corner, middle, p0, p1, l0, fl0, a, b, c), solve(1, corner, middle, p0, p1, l0, fl0, a, b, c));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		std::cout << solve() << '\n';
	}
}