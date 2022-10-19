#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, cur = 0;
	
	ll s = 0;

	std::cin >> n;

	std::vector <std::bitset <100002> > b(70);
	std::vector <int> v(70);
	std::vector <ll> a(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s ^= a[i];
	}
	
	for (int k = 0; k < 2; k++) {
		for (int i = 60; i >= 0; i--) {
			if ((s >> i & 1) == k) {
				
				++cur;
				
				for (int j = 1; j <= n; j++) {
					if (a[j] >> i & 1) {
						b[cur].set(j);
					}
				}
				
				if (!k) {
					b[cur].set(n + 1);
				}

				for (int j = 1; j < cur; j++) {
					if (b[cur][v[j]]) {
						b[cur] ^= b[j];
					}
				}
				
				for (int j = 1; j <= n; j++) {
					if (b[cur][j]) {
						v[cur] = j;
						break;
					}
				}
				
				if (!v[cur]) {
					b[cur--].reset();
					continue;
				}
				
				for (int j = 1; j < cur; j++) {
					if (b[j][v[cur]]) {
						b[j] ^= b[cur];
					}
				}
			}
		}
	}
	
	std::vector <int> ans(n + 1);
	
	for (int i = 1; i <= cur; i++) {
		ans[v[i]] = b[i][n + 1];
	}
	
	for (int i = 1; i <= n; i++) {
		std::cout << 2 - ans[i] << " \n"[i == n];
	}
	
	return 0;
}