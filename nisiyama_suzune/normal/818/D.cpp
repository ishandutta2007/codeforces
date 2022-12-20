#include <bits/stdc++.h>

int N, A;
std::vector <std::pair <int, int>> winning;
std::vector <std::pair <int, int>> tmp;
int cnt = 0;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	std::cin >> N >> A;
	for (int i = 1; i <= 1000000; ++i) {
		if (i != A) winning.push_back (std::make_pair (i, 0));
	}
	for (int n = 0; n < N; ++n) {
		int c;
		std::cin >> c;
		if (c != A) {
			auto it = std::lower_bound (winning.begin (), winning.end (), std::make_pair (c, 0));
			if (it -> first == c) ++(it -> second);
		} else {
			++cnt;
			tmp.clear ();
			for (auto i : winning) {
				if (i.second >= cnt)
					tmp.push_back (i);
			}
			winning = tmp;
		}
	}
	if (winning.empty ()) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << winning.front ().first << std::endl;
	}
}