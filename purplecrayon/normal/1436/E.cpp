//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> last(n + 2), mex(n + 2);
	int N = 1;
	while (N <= n + 2) {
		N *= 2;
	}
	vector<int> d(N + N);
	auto update = [&](int u, int x) {
		d[u += N] = x;
		for (u >>= 1; u; u >>= 1) {
			d[u] = min(d[u + u], d[u + u + 1]);
		}
	};
	auto query = [&](int l, int r) {
		l += N, r += N + 1;
		int ret = 1e9;
		while (l < r) {
			if (l & 1) {
				ret = min(ret, d[l]);
			}
			if (r & 1) {
				ret = min(ret, d[r - 1]);
			}
			l = l + 1 >> 1, r >>= 1;
		}
		return ret;
	};
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			if (last[1] + 1 < i) {
				mex[1] = 1;
			}
		} else if (query(1, a[i] - 1) > last[a[i]]) {
			mex[a[i]] = 1;
		}
		last[a[i]] = i;
		update(a[i], i);
	}
	for (int i = 1; i <= n + 1; i++) {
		if (mex[i]) {
			continue;
		}
		if (i == 1) {
			if (last[i] < n) {
				continue;
			}
		} else {
			if (query(1, i - 1) > last[i]) {
				continue;
			}
		}
		cout << i << endl;
		return 0;
	}
	cout << n + 2 << endl;
	return 0;
}