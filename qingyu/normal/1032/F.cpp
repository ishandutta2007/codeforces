#include <bits/stdc++.h>

const int N = 5e5 + 50;
const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); } 
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

int n, f[N][3];
std::vector<int> G[N];

/*
f[x][0/1/2]:
0: not in perfect matching
1: paired with its child
2: paired with its parent
*/
void dfs(int x, int fa = 0)
{
	f[x][0] = f[x][1] = f[x][2] = 1;
	int prod = 0;
	for (int y : G[x])
		if (y != fa)
		{
			dfs(y, x);
			pud(f[x][0], f[y][0] + f[y][1]);
			int t = inc(inc(f[y][0], f[y][1]), f[y][1]);
			pud(f[x][2], t);
			upd(prod, mul(f[y][2], fastpow(t, mod - 2)));
		}
	f[x][1] = mul(f[x][2], prod);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1);
	std::cout << inc(f[1][0], f[1][1]) << '\n';
	return 0;
}