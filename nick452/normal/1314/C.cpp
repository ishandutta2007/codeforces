#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1024;

int n, m;
char s[MAXN];
long long limit;
int lcp[MAXN][MAXN];
int g[MAXN];
long long f[MAXN][MAXN];
long long sumf[MAXN][MAXN];

using substr = pair<int, int>;

bool substr_less(const substr& a, const substr& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	int l = lcp[a.first][b.first];
	if (l < a.second && l < b.second)
	{
		return s[a.first + l] < s[b.first + l];
	}
	if (a.second != b.second)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> limit >> s;
	memset(lcp, 0, sizeof(lcp));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
		}
	}
	vector<substr> all_substrs;
	for (int i = 0; i < n; i++)
	{
		for (int l = 1; l <= n - i; l++)
		{
			all_substrs.push_back(make_pair(i, l));
		}
	}
	sort(all_substrs.begin(), all_substrs.end(), substr_less);
	int lo = 0;
	int hi = all_substrs.size();
	while (hi - lo > 1)
	{
		int mi = lo + (hi - lo) / 2;
		for (int i = 0; i < n; i++)
		{
			g[i] = n + 1;
		}
		for (int i = mi; i < all_substrs.size(); ++i)
		{
			auto h = all_substrs[i];
			g[h.first] = min(g[h.first], h.first + h.second);
		}
		memset(f, 0, sizeof(f));
		memset(sumf, 0, sizeof(sumf));
		f[n][0] = 1;
		sumf[n][0] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (g[i] <= n)
			{
				for (int j = 1; j <= m; j++)
				{
					f[i][j] = sumf[g[i]][j - 1];
				}
			}
			for (int j = 0; j <= m; j++)
			{
				sumf[i][j] = min(sumf[i + 1][j] + f[i][j], limit);
			}
		}
		if (f[0][m] >= limit)
		{
			lo = mi;
		}
		else
		{
			hi = mi;
		}
	}
	auto ret = all_substrs[lo];
	for (int i = 0; i < ret.second; i++)
	{
		printf("%c", s[ret.first + i]);
	}
	printf("\n");
	return 0;
}