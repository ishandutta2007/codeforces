#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

int n, m, k, l, ccc, a[200][200], x, used[200], paint[200], super[200], color[200], boo, z, ans[200];
vector <int> c[200];

void dfs(int v)
{
	used[v] = 1;     
	for (int u = 0; u < n; u++)
	{	
		if (used[u] == 0 && a[v][u] == 2)
		{
			paint[u] = paint[v];
			dfs(u);
		}
		if (used[u] == 0 && a[v][u] == 1)
		{
			paint[u] = 1 - paint[v];
			dfs(u);
		}
		if (used[u] == 1 && a[v][u] > 0 && (paint[v] + paint[u]) % 2 != a[v][u] % 2)
		{
			boo = 1; 
		}
	}
}

void dfs1(int v)
{
	used[v]  = 1;
	color[v] = x;
	for (int u = 0; u < n; u++)
		if (used[u] == 0 && a[v][u] > 0)
			dfs1(u);
}

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &k, &l, &ccc);
		k--;
		l--;
		a[k][l] = ccc + 1;
		a[l][k] = ccc + 1;
	}                                    
	for (int i = 0; i < n; i++)
		if (used[i] == 0)
		{
			dfs1(i);
			x++;
		}
	for (int i = 0; i < n; i++)
	{
		c[color[i]].push_back(i);
	}
	for (int i = 0; i < n; i++)
	{
		if (super[i] == 1)
			continue;
		for (int j = 0; j < n; j++)
			used[j] = 0;

		for (int j = 0; j < n; j++)
			paint[j] = 0;
		paint[i] = 1;
		boo = 0;
		dfs(i);     
		if (boo == 0)
		{                  
			for (int j = 0; j < (int) c[color[i]].size(); j++)
			{
				super[c[color[i]][j]] = 1;
				if (paint[c[color[i]][j]] == 1)
					ans[z++] = c[color[i]][j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (super[i] == 0)
		{
			printf("Impossible\n");
			return 0;
		}
	printf("%d\n", z);
	for (int i = 0; i < z; i++)
		printf("%d ", ans[i]);
	return 0;
}