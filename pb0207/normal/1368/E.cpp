#include<bits/stdc++.h>
using namespace std;
 
const int N=2e5+1e3+7,M=1e6+1e3+7;
 
int T,n,m;
 
int vis[N][3],f[N];
 
vector<int>v;
 
vector<int>g[N];
 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		v.clear();
		for(int i=1;i<=n;i++)
			g[i].clear(),f[i]=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<g[i].size();j++)
			{
				int v=g[i][j];
				if(f[v]<2)
					f[i]=max(f[i],f[v]+1);
			}
			if(f[i]==2)
				v.push_back(i);
		}
		printf("%d\n",(int)v.size());
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
		puts("");
	}
}