#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2002;
int n,i,j,k,a[maxn][maxn],p[maxn],q[maxn];
vector<int> g[maxn],f[maxn];
LL d[maxn];
bool u[maxn];
void dfs(int i,int p,LL s)
{
	d[i]=s;
	for(int j=0;j<g[i].size();j++)
	{
		int k=g[i][j];
		if(k==p)
			continue;
		dfs(k,i,s+f[i][j]);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0&&i!=j)
			{
				puts("NO");
				return 0;
			}
		}
	for(i=1;i<n;i++)
		p[i]=2147483647;
	for(k=0;k<n;k++)
	{
		int best=-1;
		for(i=0;i<n;i++)
			if(!u[i]&&(best==-1||p[best]>p[i]))
				best=i;
		u[i=best]=true;
		if(i!=0)
		{
			g[q[i]].push_back(i);
			f[q[i]].push_back(p[i]);
			g[i].push_back(q[i]);
			f[i].push_back(p[i]);
		}
		for(int j=0;j<n;j++)
			if(!u[j]&&a[i][j]<p[j])
			{
				p[j]=a[i][j];
				q[j]=i;
			}
	}
	for(int i=0;i<n;i++)
	{
		dfs(i,-1,0);
		for(int j=0;j<n;j++)
			if(d[j]!=a[i][j])
			{
				puts("NO");
				return 0;
			}
	}
	puts("YES");
	return 0;
}