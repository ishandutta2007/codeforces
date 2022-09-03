#include <bits/stdc++.h>
using namespace std;

const int maxn = 1111;
int n, m, lcp[maxn][maxn];
long long k;
char s[maxn];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	int l = lcp[a.first][b.first], l1 = a.second - a.first + 1, l2 = b.second - b.first + 1;
	l = min(l, min(l1, l2));
	int n1 = (l == l1 ? 0 : s[a.first + l]), n2 = (l == l2 ? 0 : s[b.first + l]);
	return n1 < n2;
}

long long dp[maxn][maxn];
const long long MAGIC = 1000000000000000000ll;
bool check(pair<int, int> sub)
{
	memset(dp, 0, sizeof(dp));
	dp[n + 1][0] = 1;
	for (int i = n; i >= 1; i--)
	{
		int bound = 0;
		if (cmp(make_pair(i, n), sub))
			bound = n + 1;
		else
		{
			int lv = min(lcp[i][sub.first], sub.second - sub.first + 1);
			if (lv == sub.second - sub.first + 1)
				bound = i + lv - 1;
			else
				bound = i + lv;
		}
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[bound + 1][j - 1];
		if (i == 1)
			return (dp[1][m] >= k);
		for (int j = 0; j <= m; j++)
		{
			dp[i][j] += dp[i + 1][j];
			if (dp[i][j] > MAGIC)
				dp[i][j] = MAGIC;
		}
	}
}

int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	scanf("%s", s + 1);
	for (int i = n; i >= 1; i--)
		for (int j = n; j >= 1; j--)
			lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
	vector<pair<int, int>> sub;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			sub.push_back(make_pair(i, j));
	sort(sub.begin(), sub.end(), cmp);
	int lb = 0, rb = sub.size(), mid;
	while (lb < rb - 1)
	{
		mid = (lb + rb) / 2;
		if (check(sub[mid]))
			lb = mid;
		else
			rb = mid;
	}
	for (int i = sub[lb].first; i <= sub[lb].second; i++)
		putchar(s[i]);
	puts("");
	return 0;
}