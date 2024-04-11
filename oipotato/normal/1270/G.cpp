#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;i++)
#define x1 fuckcjb
#define y1 fucksub
#define x2 fuckjtjl
#define y2 fucksf
const int N=1000010;
vector<int>g[N];
int fa[N],dfn[N],b[N],a[N],n,ans[N],tot;
bool flag;
void dfs(int p)
{
	dfn[p]=++tot;
	for(auto i:g[p])
	if(i!=fa[p])
	{
		if(!dfn[i])
		{
			fa[i]=p;
			dfs(i);
		}
		else
		{
			if(flag)break;
			int cnt=0;
			for(int x=p;x!=i;x=fa[x])ans[++cnt]=x;
			ans[++cnt]=i;
			flag=1;
			printf("%d\n",cnt);
			rep(j,cnt)printf("%d%c",n-ans[j]+1," \n"[j==cnt]);
			break;
		}
	}
}
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);rep(i,n)scanf("%d",&a[i]),b[i]=a[i]+n-i+1;
		reverse(b+1,b+n+1);
		flag=0;
		rep(i,n)if(b[i]==i){printf("1\n%d\n",n-i+1);flag=1;break;}
		if(flag)continue;
		rep(i,n)if(b[b[i]]==i){printf("2\n%d %d\n",n-i+1,n-b[i]+1);flag=1;break;}
		if(flag)continue;
		rep(i,n)g[i].clear();
		rep(i,n)g[b[i]].pb(i),g[i].pb(b[i]);
		rep(i,n)dfn[i]=fa[i]=0;
		tot=0;
		rep(i,n)if(!dfn[i]){fa[i]=0;dfs(i);if(flag)break;}
	}
	return 0;
}