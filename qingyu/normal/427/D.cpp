#include <bits/stdc++.h>

const int N = 2e6 + 50;

char s[N];
int len[N], ch[N][26], fa[N], v[N], p[N], tot = 1, siz[N][2], cstr;
inline int extend(int c, int last)
{
	int p = last, np = ch[p][c];
	len[np] = len[p] + 1;
	p = fa[p];
	while (p && !ch[p][c]) ch[p][c] = np, p = fa[p];
	if (!p) fa[np] = 1;
	else
	{
		int q = ch[p][c];
		if (len[q] == len[p] + 1) fa[np] = q;
		else
		{
			int nq = ++tot;
			//memcpy(ch[nq], ch[q], sizeof ch[q]);
			for (int i = 0; i < 26; ++i)
				if (len[ch[q][i]] != 0)
					ch[nq][i] = ch[q][i];
			fa[nq] = fa[q], len[nq] = len[p] + 1;
			fa[np] = fa[q] = nq;
			while (p && ch[p][c] == q) ch[p][c] = nq, p = fa[p];
		}
	}
	return np;
}
inline void ins(const char *s)
{
	int n = strlen(s), p = 1;
	for (int i = 0; i < n; ++i)
	{
		int c = s[i] - 'a';
		if (!ch[p][c]) ch[p][c] = ++tot, fa[tot] = p, v[tot] = c;
		p = ch[p][c];
		++siz[p][cstr];
	}
	++cstr;
}

inline void buildSAM()
{
	std::queue<int> que;
	for (int i = 0; i < 26; ++i) if (ch[1][i]) que.push(ch[1][i]);
	p[1] = 1;
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		p[x] = extend(v[x], p[fa[x]]);
		for (int i = 0; i < 26; ++i) if (ch[x][i]) que.push(ch[x][i]);
	}
}

inline void init()
{
	memset(v, 0, sizeof v); memset(p, 0, sizeof p);
	for (int i = 1; i <= tot; ++i) ++v[len[i]];
	for (int i = 1; i <= tot; ++i) v[i] += v[i - 1];
	for (int i = tot; i >= 1; --i) p[v[len[i]]--] = i;
	for (int i = tot; i >= 1; --i)
	{
		int x = p[i];
		siz[fa[x]][0] += siz[x][0];
		siz[fa[x]][1] += siz[x][1];
	}
	siz[0][0] = siz[0][1] = 0;
}

int main()
{
	int n;
	for (int i = 0; i < 2; ++i)
	{
		scanf("%s", s);
		ins(s);
	}
	buildSAM();
	init();
	int ans = 1e9;
	for (int i = 2; i <= tot; ++i) 
	{
		if (siz[i][0] == 1 && siz[i][1] == 1)
		{
			ans = std::min(ans, len[fa[i]] + 1);
		}
	}
	if (ans == 1e9) puts("-1");
	else printf("%d", ans);
	return 0;
}