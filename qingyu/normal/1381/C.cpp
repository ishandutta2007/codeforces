// byqingyu
#include <bits/stdc++.h>

const int N = 1e5 + 50;

int a[N], res[N];
bool die[N];
std::vector<int> ind[N], freq[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1; char ch; 
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
	int t = read();
	while (t--)
	{
		int n = read(), x = read(), y = read();
		for (int i = 0; i <= n + 1; ++i) ind[i].clear(), freq[i].clear(), die[i] = false;
		for (int i = 1; i <= n; ++i) a[i] = read(), ind[a[i]].emplace_back(i);
		for (int i = 1; i <= n + 1; ++i) freq[ind[i].size()].emplace_back(i);
		int p = n;
		for (int i = 1; i <= x; ++i)
		{
			while (freq[p].size() == 0) --p;
			int col = freq[p].back(); freq[p].pop_back(); freq[p - 1].emplace_back(col);
			res[ind[col].back()] = col; ind[col].pop_back();
		}
		while (p > 0 && freq[p].size() == 0) --p;
		if (2 * p > 2 * n - x - y)
		{
			puts("NO");
		}
		else
		{
			int rub_size = n - y;
			std::vector<int> bases;
			for (int i = 1; i <= p; ++i)
				for (auto t : freq[i])
					for (auto x : ind[t])
						bases.emplace_back(x);
			auto kill = [&](int i)
			{
				res[i] = freq[0][0], die[i] = true;
				--rub_size;
			};
			assert(bases.size() >= n - x);
			for (int i = 0; i < n - x; ++i)
			{
				res[bases[i]] = a[bases[(i + (n - x) / 2) % (n - x)]];
				if (res[bases[i]] == a[bases[i]]) kill(bases[i]);
			}
			for (int i = 0; rub_size; ++i)
			{
				if (!die[bases[i]]) 
				{
					kill(bases[i]);
				}
			}
			assert(rub_size == 0);
			puts("YES");
			for (int i = 1; i <= n; ++i) printf("%d ", res[i]);
			putchar('\n');
		}
	}
	return 0;
}