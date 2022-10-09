#include <bits/stdc++.h>
const int N = 1e6 + 50;

int n, len[N], ch[N][26], fa[N], endpos[N], v[N], q[N], tot = 1, last = 1;
char s[N];

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

int main()
{
	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; ++i) extend(s[i] - 'a');
	init();
	long long ans = 0;
	for (int i = 1; i <= tot; ++i)
	{
		int length = len[i] - len[fa[i]], cnt = endpos[i];
		ans += 1ll * length * cnt * (cnt + 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}