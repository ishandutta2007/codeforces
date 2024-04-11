#include<cstdio>
#include<vector>

using namespace std;

int n, m, k[200], sum = 0, ans = 0, l, used[300];
vector <int> c[300];

void dfs (int v)
{
	used[v] = 1;
	for (int i = 0; i < (int) c[v].size(); i++)
		if (used[c[v][i]] == 0)
			dfs(c[v][i]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k[i]);
		sum += k[i];
		for (int j = 0; j < k[i]; j++)
		{
			scanf("%d", &l);
			l--;
			c[i].push_back(n + l);
			c[n + l].push_back(i);	
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 0)
		{
			dfs(i);
			ans++;
		}
	}
	if (sum == 0)
		printf("%d\n", ans);
	else
		printf("%d\n", ans - 1);
	return 0;
}