#include <bits/stdc++.h>

const int N = 1e6 + 50;

int S[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1;
	char ch;
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int main()
{ 
	int n = read();
	unsigned Q = 0;
	for (int i = 1; i <= n; ++i) Q ^= read();
	for (int i = 1; i <= n; ++i) S[i] = S[i - 1] ^ i;
	for (int i = 1; i <= n; ++i)
	{
		int z = n / i;
		if (z & 1) Q ^= S[i - 1];
		Q ^= S[n % i];
	}
	std::cout << Q;
	return 0;
}