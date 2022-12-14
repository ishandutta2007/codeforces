#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n, x, h[2005], used[4005], hei = 0, a[2005], tin[2005], tout[2005], W, t = 0;
vector <int> c[2005], b;

void dfs (int v)
{
	used[v] = 1;
	h[v] = hei++;
	tin[v] = t++;
	for (int u = 0; u < (int) c[v].size(); u++)
		if (used[c[v][u]] == 0)
			dfs(c[v][u]);
	hei--;
	tout[v] = t++;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		c[i + 1].push_back(a[i]);  
		c[a[i]].push_back(i + 1);  
	}
	dfs(0);
	//printf("%d\n", h[x]);
	for (int i = 1; i <= n; i++)
	{
		if ((int) c[i].size() == 1)
		{
			if (tin[i] >= tin[x] && tout[i] <= tout[x])
				continue;
			b.push_back(h[i]);
		}
	}
	W = 2000;
	used[0] = 1;
	for (int i = 1; i <= W; i++)
		used[i] = 0;
	for (int i = 0; i < (int) b.size(); i++)
		for (int j = W; j >= 0; j--)
			if (used[j] == 1)
				used[j + b[i]] = 1;
   	for (int i = 0; i <= W; i++)
   		if (used[i] == 1)
   			printf("%d\n", h[x] + i);
	return 0;
}