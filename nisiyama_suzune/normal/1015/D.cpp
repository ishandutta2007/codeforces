#include <bits/stdc++.h>

long long N, K, S;
std::vector <long long> ans;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> K >> S;
	long long cur = 1;
	while (K >= 1 && S - (N - 1) >= K - 1) {
		cur = N - cur + 1;
		ans.push_back (cur); 
		S -= (N - 1); --K;
	}
	if (K >= 1 && S > K) {
		cur = cur == 1 ? cur + S - (K - 1) : cur - (S - (K - 1));
		ans.push_back (cur);
		S -= (S - (K - 1)); --K;
	}
	while (K >= 1) {
		cur = cur == 1 ? cur + 1 : cur - 1;
		ans.push_back (cur);
		--S; --K;
	}
	if (S == 0 && K == 0) {
		std::cout << "YES\n";
		for (int i = 0; i < ans.size (); ++i) std::cout << ans[i] << " \n"[i + 1 == ans.size ()];
	} else {
		std::cout << "NO\n";
	}
}