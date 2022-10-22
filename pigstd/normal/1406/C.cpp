#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int T,n,sum[M],fa[M],minn,ssum;
int x,y,mm[M],out[M];

vector<int>e[M];

void dfs(int u,int fat)
{
	sum[u]=1,fa[u]=fat;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to!=fat)
			dfs(to,u),sum[u]+=sum[to];
	}
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to!=fat)
			mm[u]=max(mm[u],sum[to]);
	}
	mm[u]=max(mm[u],n-1-sum[u]);
	minn=min(minn,mm[u]);
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;minn=n+10;
		for (int i=1;i<n;i++)
		{
			cin>>x>>y;
			e[x].push_back(y),e[y].push_back(x); 
			out[x]++,out[y]++;
		}
		for (int i=1;i<=n;i++)
			if (out[i]==1)
			{
				x=i;y=e[i][0];
				e[x].erase(find(e[x].begin(),e[x].end(),y));
				e[y].erase(find(e[y].begin(),e[y].end(),x));
				break;
			}
		dfs(x==1?2:1,0);
		for (int i=1;i<=n;i++)
			if (mm[i]==minn)
			{
				printf("%d %d\n%d %d\n",x,y,x,i);
				break;
			}
		for (int i=1;i<=n;i++)e[i].clear();
		for (int i=0;i<=n;i++)fa[i]=sum[i]=out[i]=mm[i]=0;
	}
	return 0;
}