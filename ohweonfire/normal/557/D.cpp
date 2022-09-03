#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
vector<int> g[maxn];
int col[maxn];
long long cnt[2];
int n,m;
bool duang;
void dfs(int x,int c)
{
	if(duang)return;
	col[x]=c;
	cnt[c]++;
	for(int i=0;i<int(g[x].size());i++)
		if(col[g[x][i]]==-1)
			dfs(g[x][i],c^1);
		else if(col[g[x][i]]==c)
		{
			duang=true;
			return;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m==0)
	{
		printf("3 %I64d\n",n*1ll*(n-1)*(n-2)/6);
		return 0;
	}
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)duang|=(g[i].size()>1);
	if(!duang)
	{
		printf("2 %I64d\n",(n-2)*1ll*m);
		return 0;
	}
	duang=false;
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n&&!duang;i++)if(col[i]==-1)dfs(i,0);
	if(duang)
	{
		printf("0 1\n");
		return 0;
	}
	memset(col,-1,sizeof(col));
	long long ans=0;
	for(int i=1;i<=n;i++)if(col[i]==-1)
	{
		cnt[0]=cnt[1]=duang=0;
		dfs(i,0);
		ans+=cnt[0]*cnt[0]-cnt[0];
		ans+=cnt[1]*cnt[1]-cnt[1];
	}
	printf("1 %I64d\n",ans/2);
	return 0;
}