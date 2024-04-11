#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

const int root = 212;

signed main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int tt; std::cin >> tt;
	while (tt--){
		int n; std::cin >> n;
		std::vector <int> a(n);
		for (auto &x: a) std::cin >> x;

		int mask = 0;
		auto Sorting = [&]() {
			std::sort(a.begin(), a.end(), [&](int x, int y){
				return (x & (~mask)) < (y & (~mask));
			});
		};

		std::vector <int> ans;
		Sorting();
		while (!a.empty() && (a.back() & (~mask)) > 0) {
			ans.push_back(a.back());
			mask |= a.back();
			a.pop_back();
			Sorting();
		}

		for (auto &x: a) ans.push_back(x);

		for (auto &x: ans) std::cout << x << ' ';
		std::cout << '\n';

	}
	return 0;
}