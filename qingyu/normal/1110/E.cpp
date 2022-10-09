#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cctype>
#include <cstdlib>

constexpr int N = 1e6 + 50;
int n;
int A[N], B[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		A[i] = read();
	for (int i = 1; i <= n; ++i)
		B[i] = read();
	if (A[1] != B[1] || A[n] != B[n])
		printf("No");
	else
	{
		for (int i = n; i > 0; --i)
			A[i] -= A[i - 1], B[i] -= B[i - 1];
		std::sort(A + 1, A + n + 1);
		std::sort(B + 1, B + n + 1);
		for (int i = 2; i < n; ++i)
			if (A[i] != B[i]) return printf("No"), 0;
		printf("Yes");
	}
	return 0;
}