#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E6;
int ans[MAXN];
bool col[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		string s;
		cin >> n >> m >> s;
		fill(ans, ans + n * m, 0);
		fill(col, col + m, 0);
		int cnt = 0;
		for (int i = 0; i < n * m; i++)
		{
			if (i >= m)
				ans[i] += ans[i - m];
			cnt += s[i] == '1';
			if (cnt)
			{
				ans[i]++;
			}
			if (i >= m - 1)
				cnt -= s[i - m + 1] == '1';
		}
		cnt = 0;
		for (int i = 0; i < n * m; i++)
		{
			if (s[i] == '1' && !col[i % m])
			{
				cnt++;
				col[i % m] = true;
			}
			ans[i] += cnt;
		}
		for (int i = 0; i < n * m; i++)
		{
			cout << ans[i] << " \n"[i == n * m - 1];
		}
	}
	return 0;
}