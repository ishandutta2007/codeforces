#include <bits/stdc++.h>
 
const int N = 3e5 + 50;
typedef long long ll;
 
std::vector<int> G[N];
 
int min_ans, max_ans, n, m, s, t, K, P[N], d[N];
int head[N], nxt[N], ver[N], cnt;
 
inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}
 
 
void dfs(int x)
{
	std::queue<int> Q;
	Q.push(x);
	while (Q.empty() == false)
	{
		int y = Q.front(); Q.pop();
		for (auto v: G[y])
		{
			if (d[v] == 0)
			{
				d[v] = d[y] + 1;
				Q.push(v);
			}
		}
	}
}
 
void work(int j = 1)
{
	if (j == K) return;
	bool max_added = false;
	for (int i = head[P[j]]; i; i = nxt[i])
	{
		int y = ver[i];
		if ((d[P[j]] != d[y] + 1) && y == P[j + 1])
		{
			++min_ans;
			if (!max_added) ++max_ans;
			break;
		}
		if (d[P[j]] == d[y] + 1 && y != P[j + 1] && !max_added)
		{
			++max_ans;
			max_added = true;
		}
	}
	work(j + 1);
}
 
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
	n = read(), m = read();
	for (int i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		add(u, v); G[v].push_back(u);
	}
	K = read();
	for (int i = 1; i <= K ; ++i) P[i] = read();
	s = P[1], t = P[K];
	d[t]=1;
	dfs(t);
	
	work(1);
	printf("%d %d", min_ans, max_ans);
	return 0;
}