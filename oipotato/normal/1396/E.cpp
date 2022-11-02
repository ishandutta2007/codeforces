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
const int N=100010;
set<pair<int,int>,greater<pair<int,int>>>s[N],S;
set<pair<int,int>>pool;
vector<int>g[N];
int a[N],c[N],dfn[N],siz[N],n,l,tot;
long long k,r;
void modify(int x,int y){for(;x<=n;x+=x&(-x))c[x]+=y;}
int get(int x){int s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
void dfs(int p,int fa)
{
	siz[p]=1;
	for(auto i:g[p])if(i!=fa)dfs(i,p),siz[p]+=siz[i];
}
int find(int p,int fa)
{
	for(auto i:g[p])if(i!=fa&&siz[i]>n-siz[i])return find(i,p);
	return p;
}
void work(int p,int fa,set<pair<int,int>,greater<pair<int,int>>>&s,int dep)
{
	dfn[p]=++tot;siz[p]=1;s.insert(mp(dep,p));
	for(auto i:g[p])if(i!=fa)work(i,p,s,dep+1),siz[p]+=siz[i];
	l+=siz[p]&1;r+=siz[p];
}
int main()
{
	scanf("%d%lld",&n,&k);
	rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
	dfs(1,0);
	int R=find(1,0);
	for(auto i:g[R])work(i,R,s[i],1),S.insert(mp(siz[i],i));
	rep(i,n)if(i!=R)pool.insert(mp(dfn[i],i));
	if(k<l||k>r||(k&1)!=(r&1)){puts("NO");return 0;}
	puts("YES");
	for(;k<r;)
	{
		auto it=S.begin();
		int u=it->second,re=it->first;
		S.erase(it);S.insert(mp(re-2,u));
		it=s[u].begin();
		int id=it->second,dep=it->first;
		for(;;)
		{
			if(r-dep*2>=k&&get(dfn[id]+siz[id]-1)-get(dfn[id]-1)+2<=siz[id])break;
			s[u].erase(it);
			it=s[u].begin();
			id=it->second;dep=it->first;
		}
		auto it2=pool.lower_bound(mp(dfn[id],id));
		int x=it2->second;it2++;
		int y=it2->second;
		pool.erase(mp(dfn[x],x));
		pool.erase(mp(dfn[y],y));
		modify(dfn[x],1);modify(dfn[y],1);
		printf("%d %d\n",x,y);
		r-=2*dep;
	}
	int cnt=1;a[1]=R;
	for(auto i:pool)a[++cnt]=i.second;
	rep(i,cnt/2)printf("%d %d\n",a[i],a[i+cnt/2]);
	return 0;
}