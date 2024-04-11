//qwq
#pragma GCC optimize(3)
#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 24, P = 1e9 + 7;
int n, m, XA, XB, f[1 << N], dis[1 << N];

inline char nc() {
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read() {
	ll res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main() {
	n = read();
	for (int i = 0; i < n; i++)
		dis[1 << i] = read();
	m = read();
	if (m > 0) XA = read();
	if (m > 1) XB = read();
	f[0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		int j = i & -i, k = i;
		dis[i] = dis[i ^ j] + dis[j];
		if (dis[i] != XA && dis[i] != XB)
			while (k) {
				j = k & -k; 
				f[i] += f[i ^ j];
				if (f[i] >= P) f[i] -= P;
				k ^= j;
			}
	}
	printf("%d", f[(1 << n) - 1]);
	return 0;
}