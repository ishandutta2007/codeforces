#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9+7;

pair<int, int> how_many_written(int n) {
	int odd_set = 0, even_set = 0;
	int sz = 1, parity = 1;
	while (n > 0) {
		int written = min(n, sz);
		if (parity == 1) {
			odd_set += written;
		} else {
			even_set += written;
		}
		parity ^= 1;

		n -= written; sz *= 2;
	}
	return {odd_set, even_set};
}

int solve(int n) {
	auto [odd, even] = how_many_written(n);
	odd %= M; even %= M;

	int ans = odd*odd % M;
	ans += (even*even + even) % M;
	ans %= M;

	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int l, r; cin >> l >> r;
	cout << (solve(r) - solve(l-1) + M) % M << '\n';

	return 0;
}