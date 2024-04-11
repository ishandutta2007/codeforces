#include <bits/stdc++.h>

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
	long long res = 0, neg = 1;
	char ch;
	do 
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	}	while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}
inline char rc()
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	return ch;
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

struct storage
{
	std::vector<int> arr, version;
	int current;
	storage(int n) : arr(n), version(n), current(0)
	{
	}
	int& operator[](int k)
	{
		if (version[k] < current) arr[k] = 0, version[k] = current;
		return arr[k];
	}
	void reset()
	{
		++current;
	}
};

int main()
{
	int n = read();
	storage f(n + 1), g(n + 1);
	std::stack<int> s;
	std::vector<int> ans, a(n), b(n);
	for (int i = 0; i < n; ++i) a[i] = b[i] = read();
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());
	for (int i = 0; i < n; ++i) a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
	for (int i = 0; i < n; ++i)
	{
		int x = a[i];
		if (g[x] || f[x] == 3)
		{
			if (f[x] == 3) g[x] = x;
			for (int j : {0, 1})
				ans.push_back(b[g[x] - 1]), ans.push_back(b[x - 1]);
			f.reset(); g.reset();
			while (!s.empty()) s.pop();
		}
		else
		{
			while (!s.empty() && f[x] >= 1)
			{
				int y = s.top(); s.pop();
				if (x == y) break;
				g[y] = x; --f[y];
			}
			++f[x];
			s.push(x);
		}
	}
	output(ans.size(), '\n');
	for (int x : ans) output(x);
}