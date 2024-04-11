//...
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <cctype>
#include <iostream>

constexpr int N = 5555;

int n, M[N][N], S[N][N];

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

inline int read_hex()
{
	int res = 0;
	char ch;
	do ch = nc(); while (!isdigit(ch) && !isalpha(ch));
	res = res * 10;
	if (isdigit(ch)) res += ch - '0';
	if (isalpha(ch)) res += ch - 'A' + 10;
	return res;
}

inline int query(int X1, int Y1, int X2, int Y2)
{
	return S[X2][Y2] - S[X2][Y1 - 1] - S[X1 - 1][Y2] + S[X1 - 1][Y1 - 1];
}

int main()
{
	int n = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= (n >> 2); ++j)
		{
			int d = read_hex();
			for (int k = (j << 2); k > ((j - 1) << 2); --k)
			{
				M[i][k] = d & 1;
				d >>= 1;
			}
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			S[i][j] = S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1] + M[i][j];
		}
	for (int i = n; i > 0; --i)
	{
		if (n % i == 0)
		{
			int g = n / i;
			for (int j = 1; j <= g; ++j)
				for (int k = 1; k <= g; ++k)
				{
					int u = query((j - 1) * i + 1, (k - 1) * i + 1, j * i, k * i);
					if (u != 0 && u != i * i)
					{
						goto failed;
					}
				}
			printf("%d", i);
			return 0;
		}
		failed:;
	}
	return 0;
}