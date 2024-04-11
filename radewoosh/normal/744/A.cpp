#include <bits/stdc++.h>
using namespace std;

int n, m, k;

vector <int> graf[1007];

int faj[1007];
int bylo[1007];

vector <int> wek;

int wyn;

int dfs(int v)
{
	if (bylo[v])
		return 0;
	bylo[v]=1;
	int ret=1;
	for (int i=0; i<graf[v].size(); i++)
		ret+=dfs(graf[v][i]);
	return ret;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=k; i++)
	{
		int p1;
		scanf("%d", &p1);
		faj[p1]=1;
	}
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	for (int i=1; i<=n; i++)
		if (faj[i])
			wek.push_back(dfs(i));
	sort(wek.begin(), wek.end());
	for (int i=1; i<=n; i++)
		wek.back()+=dfs(i);
	for (int i=0; i<wek.size(); i++)
		wyn+=wek[i]*(wek[i]-1)/2;
	printf("%d\n", wyn-m);
	return 0;
}