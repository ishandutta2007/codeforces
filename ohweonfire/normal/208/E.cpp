#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100005;
vector<int> g[maxn],c[maxn];
int f[maxn][20],d[maxn],begin[maxn],end[maxn],time,n,Q,x,y;
void dfs(int x,int deep)
{
	d[x]=deep;
	begin[x]=time;
	c[deep].push_back(time);
	time++;
	for(int i=0;i<g[x].size();i++)
		dfs(g[x][i],deep+1);
	end[x]=time;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i][0]);
		g[f[i][0]].push_back(i);
	}
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=n;i++)
		if(f[i][0]==0)
			dfs(i,0);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&x,&y);
		int px=x;
		for(int i=0;i<20;i++)
			if(y>>i&1)
				px=f[px][i];
		if(px==0)
			puts("0");
		else
			printf("%d ",lower_bound(c[d[x]].begin(),c[d[x]].end(),end[px])-
						 lower_bound(c[d[x]].begin(),c[d[x]].end(),begin[px])-1);
	}
	return 0;
}