#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
	int m;
	std::cin >> m;
	std::cout.precision(15);
	std::vector<long long> a(1, 0), sum(1, 0);
	int p = 0;
	auto val = [&](int p) {
		return a.back() - 1.0L * (a.back() + sum[p]) / (p + 1);
	};
	while (m--) {
		int op, x;
		std::cin >> op;
		if (op == 1) {
			std::cin >> x;
			a.push_back(x);
			sum.push_back(sum.back() + x);
		}
		else {
			std::cout << 1.0L * val(p) << '\n';
		}
		while (p + 1 < sum.size() && val(p + 1) > val(p)) ++p;
	}
}