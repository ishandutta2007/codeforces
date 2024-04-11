#include <bits/stdc++.h>
using namespace std;

int n, k;

vector <int> graf[1000007];

int wyj[1000007];

int dp[1000007];
int oj[1000007];

int naj[1000007];

int c;

int l;
vector <int> wek[1000007];

priority_queue < pair <int,int> > kol;

void dfs1(int v)
{
	dp[v]=wyj[v];
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj[v])
			continue;
		oj[graf[v][i]]=v;
		dfs1(graf[v][i]);
		dp[v]+=dp[graf[v][i]];
		naj[v]=max(naj[v], dp[graf[v][i]]);
	}
}

void dfs2(int v, int ojc)
{
	if (wyj[v])
		wek[l].push_back(v);
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==ojc)
			continue;
		dfs2(graf[v][i], v);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	for (int i=1; i<=2*k; i++)
	{
		int p1;
		scanf("%d", &p1);
		wyj[p1]=1;
	}
	dfs1(1);
	for (int i=1; i<=n; i++)
		if (naj[i]<=k && 2*k-dp[i]<=k)
			c=i;
	printf("1\n%d\n", c);
	if (wyj[c])
	{
		l++;
		wek[l].push_back(c);
	}
	for (int i=0; i<graf[c].size(); i++)
	{
		l++;
		dfs2(graf[c][i], c);
	}
	for (int i=1; i<=l; i++)
		kol.push({(int)wek[i].size(), i});
	for (int h=1; h<=k; h++)
	{
		pair <int,int> x, y;
		x=kol.top();
		kol.pop();
		y=kol.top();
		kol.pop();
		printf("%d %d %d\n", wek[x.second].back(), wek[y.second].back(), c);
		wek[x.second].pop_back();
		wek[y.second].pop_back();
		x.first--;
		y.first--;
		kol.push(x);
		kol.push(y);
	}
	return 0;
}