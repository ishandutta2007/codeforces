#include <bits/stdc++.h>

int N, M;
int cnt[200];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int l, r; std::cin >> l >> r;
		for (int j = l; j <= r; ++j) ++cnt[j];
	}
	std::vector <int> ans;
	for (int i = 1; i <= M; ++i)
		if (cnt[i] == 0) ans.push_back (i);
	std::cout << ans.size () << "\n";
	for (int i = 0; i < ans.size (); ++i) std::cout << ans[i] << " \n"[i + 1 == ans.size ()];
	return 0;
}