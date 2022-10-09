#include <bits/stdc++.h>

const int N = 150;

int n, m, a[N][N];

template <long long T>
struct fast_io
{
	char p[T], q[T], * p1, * p2, * q1, * q2;
	fast_io()
	{
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char c)
	{
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1 << 20> io;
inline long long read()
{
	long long res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void put(int64_t x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(int64_t x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}
inline int rd()
{
	char ch;
	do ch = io.gc(); while (ch != 48 && ch != 49);
	return ch - 48;
}

std::vector<std::tuple<int, int, int, int, int, int>> storage;

inline int chebyshev_distance(int x1, int y1, int x2, int y2)
{
	return std::max(std::abs(x1 - x2), std::abs(y1 - y2));
}

inline bool validate(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return chebyshev_distance(x1, y1, x2, y2) == 1 && chebyshev_distance(x1, y1, x3, y3) == 1 && chebyshev_distance(x2, y2, x3, y3);
}

inline void operate(int x1, int y1, int x2, int y2, int x3, int y3)
{
#ifdef SECURE_MODE
	assert(validate(x1, y1, x2, y2, x3, y3));
#endif
	a[x1][y1] ^= 1, a[x2][y2] ^= 1, a[x3][y3] ^= 1;
	storage.emplace_back(x1, y1, x2, y2, x3, y3);
}
// f(n, m)
inline void reduce_rows()
{
	for (int i = 1; i <= n - 2; ++i)
	{
		std::vector<int> ones;
		for (int j = 1; j <= m - 1; ++j)
		{
			ones.clear();
			if (a[i][j]) ones.emplace_back(j);
			if (a[i][j + 1]) ones.emplace_back(j + 1);
			if (ones.size() == 1)
			{
				operate(i, ones[0], i + 1, j, i + 1, j + 1);
			}
			else if (ones.size() == 2)
			{
				operate(i, ones[0], i, ones[1], i + 1, j + 1);
			}
		}
	}
}

// f(2, m)
inline void reduce_columns()
{
	for (int j = 1; j <= m - 2; ++j)
	{
		std::vector<int> ones;
		if (a[n - 1][j]) ones.emplace_back(n - 1);
		if (a[n][j]) ones.emplace_back(n);
		if (ones.size() == 1)
		{
			operate(ones[0], j, n - 1, j + 1, n, j + 1);
		}
		else if (ones.size() == 2)
		{
			operate(ones[0], j, ones[1], j, n, j + 1);
		}
	}
}

// f(2, 2)
inline void solve_corner_cases()
{
	std::vector<std::pair<int, int>> zeros, ones;
	while (true)
	{
		zeros.clear(); ones.clear();
		for (int i = n - 1; i <= n; ++i)
			for (int j = m - 1; j <= m; ++j)
				if (a[i][j]) ones.emplace_back(i, j);
				else zeros.emplace_back(i, j);
		if (ones.size() == 0) return;
		else if (ones.size() >= 3) // 3 to 0, 4 to 1
		{
			auto x = ones[0], y = ones[1], z = ones[2];
			operate(x.first, x.second, y.first, y.second, z.first, z.second);
		}
		else if (ones.size() <= 2) // 2 to 3, 1 to 2
		{	
			auto x = ones[0], y = zeros[0], z = zeros[1];
			operate(x.first, x.second, y.first, y.second, z.first, z.second);
		}
	}	
}


int main()
{
	int T = read();
	while (T--)
	{
		storage.clear();
		n = read(), m = read();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				a[i][j] = rd();
		reduce_rows();
		reduce_columns();
		solve_corner_cases();
#ifdef SECURE_MDOE
		assert(storage.size() <= n * m);
#endif
		printf("%d\n", storage.size());
		int a, b, c, d, e, f;
		for (auto p : storage)
		{
			std::tie(a, b, c, d, e, f) = p;
			printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
		}
	}
	return 0;
}