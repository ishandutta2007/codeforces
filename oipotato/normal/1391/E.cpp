#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=500010;
int dep[N],pre[N],n,m;
vector<int>g[N],v[N];
vector<pair<int,int>>ans;
void dfs(int p)
{
	for(auto i:g[p])
	if(!dep[i])
	{
		pre[i]=p;
		dep[i]=dep[p]+1;
		dfs(i);
	}
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		rep(i,n)g[i].clear(),dep[i]=0;
		rep(i,m){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
		dfs(dep[1]=1);
		int pos=-1;
		rep(i,n)if(dep[i]>=(n+1)/2){pos=i;break;}
		if(pos!=-1)
		{
			puts("PATH");
			printf("%d\n",dep[pos]);
			int now=pos;
			rep(i,dep[pos])printf("%d%c",now," \n"[i==dep[pos]]),now=pre[now];
		}
		else
		{
			puts("PAIRING");
			rep(i,n)v[i].clear();
			rep(i,n)v[dep[i]].pb(i);
			ans.clear();
			rep(i,n)
			{
				int cnt=v[i].size();
				for(int j=0;j+1<cnt;j+=2)ans.pb(mp(v[i][j],v[i][j+1]));
			}
			printf("%d\n",(int)ans.size());
			for(auto i:ans)printf("%d %d\n",i.first,i.second);
		}
	}
	return 0;
}