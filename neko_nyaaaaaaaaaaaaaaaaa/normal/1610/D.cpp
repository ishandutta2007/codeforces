#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9+7;

int modpow(int n, int k) {
	int ans = 1;
	while (k) {
		if (k % 2) ans = (ans*n) % M;
		n = (n*n) % M; k /= 2;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a; int odd = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % 2) odd++;
		else a.push_back(x);
	}

	n = a.size();

	int ans = 0;
	ans = (modpow(2, odd) + M - 1)*modpow(2, n) % M;

	vector<int> cnt(31);
	for (int i: a) {
		cnt[__builtin_ctzll(i)]++;
	}

	for (int i = 0; i < 31; i++) {
		if (cnt[i] >= 2) {
			// pick an even number
			int p1 = (modpow(2, cnt[i] - 1) + M - 1) % M;
			// pick others

			int sm = 0;
			for (int j = i+1; j < 31; j++) {
				sm += cnt[j];
			}
			int p2 = modpow(2, sm) % M;

			ans = (ans + p1*p2) % M;
		}
	}

	cout << ans << '\n';

	return 0;
}