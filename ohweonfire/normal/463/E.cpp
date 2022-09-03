#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int f[100005],val[100005],n,q,x,y,z;
vector<int> g[100005];
void dfs(int x,int father)
{
	f[x]=father;
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]!=father)
			dfs(g[x][i],x);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	while(q--)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&z);
			int i;
			for(i=f[z];i;i=f[i])
				if(gcd(val[i],val[z])>1)
					break;
			if(i==0)
				puts("-1");
			else
				printf("%d\n",i);
		}
		else
		{
			scanf("%d%d",&y,&z);
			val[y]=z;
		}
	}
	return 0;
}