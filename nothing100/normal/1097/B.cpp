#include <bits/stdc++.h>
using namespace std;

int n, flag;
int a[21];

void dfs(int t, int sum)
{
	if (t > n)
	{
		if (sum % 360 == 0)
		{
			flag = 1;
		}
		return;
	}
	dfs(t + 1, sum + a[t]);
	dfs(t + 1, sum - a[t]);
}

int main()
{
//	freopen("1.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
	dfs(1, 0);
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}