#include <bits/stdc++.h>
const int N = 1e6 + 50;

int n, f[N], len[N], ch[N][26], fa[N], endpos[N], v[N], q[N], tot = 1, last = 1;
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

inline void calc(const char *s)
{
	for (int i = 2; i <= n; ++i)
	{
		int j = f[i - 1];
		while (j && s[j + 1] != s[i]) j = f[j];
		if (s[j + 1] == s[i]) f[i] = j + 1;
	}
}

int main()
{
	scanf("%s", s + 1); 
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) extend(s[i] - 'A');
	init();
	calc(s);
	std::vector<int> vec, ans;
	vec.push_back(n);
	for (int j = f[n]; j; j = f[j]) vec.push_back(j);
	std::reverse(vec.begin(), vec.end());
	ans.resize(vec.size());
	int p = 1, c = 1, qw = 0;
	for (int i : vec)
	{
		while (c <= i && p) p = ch[p][s[c] - 'A'], ++c;
		if (!p) break;
		ans[qw++] = endpos[p];
	}
	printf("%d\n", vec.size());
	for (int i = 0; i < vec.size(); ++i)
	{
		printf("%d %d\n", vec[i], ans[i]);
	}	
	return 0;
}