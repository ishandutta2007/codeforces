#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <cctype>
#include <cstring>
#include <cassert>
#include <ctime>
#include <functional>
#include <map>

inline char nc() {
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int a[3650], b[3650];
//qwqwq
int main() {
	int n = read();
	a[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int x = read();
		memcpy(b, a, 3600);
		memset(a, 0, sizeof(a));
		for (int i = 0; i <= 360; ++i) { if (b[i]) a[(i + x + 360) % 360] = a[(i - x + 360) % 360] =  1; }
	}
	if (a[0] == 1) puts("YES");
	else puts("NO");
	return 0;
}