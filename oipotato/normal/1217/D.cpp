#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
vector<pair<int,int>>g[5010];
int co[5010],dfn[5010],in[5010],tot,n,m,ans;
void dfs(int p)
{
	dfn[p]=++tot;in[p]=1;
	for(auto i:g[p])
	{
		int x=i.first;
		if(!dfn[x]){co[i.second]=1;dfs(x);}
		else if(in[x]){co[i.second]=2;ans=2;}
		else co[i.second]=1;
	}
	in[p]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,m){int x,y;scanf("%d%d",&x,&y);g[x].push_back(make_pair(y,i));}
	ans=1;
	rep(i,n)if(!dfn[i])dfs(i);
	printf("%d\n",ans);
	rep(i,m)printf("%d%c",co[i]," \n"[i==m]);
	return 0;
}