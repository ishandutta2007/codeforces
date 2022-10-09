#include <bits/stdc++.h>
const int N = 2e6 + 50;

int n, m, f[N], len[N], ch[N][26], fa[N], endpos[N], v[N], q[N], tot = 1, last = 1;
char s[N];
bool vis[N];

inline void extend(int x)
{
	int p = last, np = last = ++tot;
	endpos[np] = 1, len[np] = len[p] + 1;
	while (p && !ch[p][x]) ch[p][x] = np, p = fa[p];
	if (!p) fa[np] = 1;
	else
	{
		int q = ch[p][x];
		if (len[q] == len[p] + 1) fa[np] = q;
		else
		{
			int nq = ++tot;
			memcpy(ch[nq], ch[q], sizeof ch[q]);
			fa[nq] = fa[q], len[nq] = len[p] + 1;
			fa[np] = fa[q] = nq;
			while (p && ch[p][x] == q) ch[p][x] = nq, p = fa[p];
		}
	}
}

inline void init()
{
	for (int i = 1; i <= tot; ++i) ++v[len[i]];
	for (int i = 1; i <= tot; ++i) v[i] += v[i - 1];
	for (int i = tot; i >= 1; --i) q[v[len[i]]--] = i;
	for (int i = tot; i >= 1; --i)
	{
		int x = q[i];
		endpos[fa[x]] += endpos[x];
	}
	endpos[0] = 0;
}

inline void kmp(const char *s, int n)
{
	f[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		int j = f[i - 1];
		while (j && s[j + 1] != s[i]) j = f[j];
		if (s[j + 1] == s[i]) f[i] = j + 1;
		else f[i] = 0;
	}
}

int main()
{
	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; ++i) extend(s[i] - 'a');
	init();
	scanf("%d", &m);
	long long ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", s);
		int n = strlen(s);
		kmp(s - 1, n);
		for (int i = 0; i <= n; ++i) vis[i] = false;
		int j = n, period = n, p = 1, cur = 0;
		while (j) vis[j] = true, j = f[j];
		for (int i = 1; i < n; ++i) if (vis[i] && vis[n - i]) { period = i; break; }
		for (int j = 0; j < period; ++j)
		{
			while (cur < j + n && ch[p][s[cur % n] - 'a']) p = ch[p][s[cur % n] - 'a'], ++cur;
			if (cur - j == n) ans += endpos[p];
			if (j < cur)
			{
				if (len[fa[p]] >= cur - j - 1) p = fa[p];
			}
		}
		printf("%lld\n", ans);
		ans = 0;
	}
	return 0;
}