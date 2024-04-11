// By Qingyu
#include <bits/stdc++.h>

const int N = 2e5 + 50;

int col[N], deg[N];
std::vector<int> G[N];

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
	int T = read();
	while (T--)
	{
		int n = read(), m = read();
		for (int i = 1; i <= n; ++i) std::vector<int>().swap(G[i]), col[i] = 0, deg[i] = 0;
		for (int i = 1; i <= m; ++i)
		{
			int x = read(), y = read();
			G[x].emplace_back(y);
			++deg[y];
		}	
		std::queue<int> Q; std::vector<int> v;
		for (int i = 1; i <= n; ++i) if (!deg[i]) Q.push(i);
		while (Q.empty() == false)
		{
			int x = Q.front(); Q.pop();
			for (auto y : G[x])
			{
				col[y] = std::max(col[y], (col[x] + 1) % 3);
				if (--deg[y] == 0)
				{
					Q.push(y);
					if (col[y] == 2) v.emplace_back(y);
				}
			}
		}
		printf("%d\n", v.size());
		for (auto x : v) printf("%d ", x);
		putchar('\n');
				
	}
	return 0;
}