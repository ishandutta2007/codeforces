#pragma comment(linker, "/stack:336777216")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

inline char gc() {
	static char buf[1 << 16];
	static size_t bc, be;
	if (bc >= be) {
		buf[0] = 0, bc = 0;
		be = fread(buf, 1, sizeof(buf), stdin);
	}
	return buf[bc++];
}

int readInt() {
	int a, c;
	while ((a = gc()) < 40);
	if (a == '-') return -readInt();
	while ((c = gc()) >= 48) a = a * 10 + c - 480;
	return a - 48;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n = readInt(), q = readInt();
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = readInt();
	}

	while (q--) {
		int t = readInt(), l = readInt(), r = readInt(), x = readInt(); l--;

		if (t == 1) {
			for (; l+4 < r; l += 4) {
				a[l] -= a[l] > x ? x : 0;
				a[l+1] -= a[l+1] > x ? x : 0;
				a[l+2] -= a[l+2] > x ? x : 0;
				a[l+3] -= a[l+3] > x ? x : 0;
			}
			for (; l < r; l++) {
				a[l] -= a[l] > x ? x : 0;
			}
		} else {
			int ans = 0;
			for (; l+4 < r; l += 4) {
				ans += (a[l] == x) + (a[l+1] == x) + (a[l+2] == x) + (a[l+3] == x);
			}
			for (; l < r; l++) {
				ans += (a[l] == x);
			}
			cout << ans << '\n';
		}
	}

	return 0;
}