#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int K=1000;
const int N=200010;
int n,m,opt[N],x[N],y[N],last;
set<pair<int,int>>S,s;
vector<int>g[N];
bool in[N];
int par[N];
pair<int,int>tmp[(K<<1)+10];
int qu[N];
int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
void rebuild(int st)
{
	rep(i,n)par[i]=i;
	s.clear();
	int cnt=0;
	rep(i,K)
	{
		if(st+i>m)break;
		//if(opt[st+i]==2)continue;
		int a=x[st+i],b=y[st+i];
		tmp[++cnt]=mp((a-1)%n+1,(b-1)%n+1);
		tmp[++cnt]=mp(a%n+1,b%n+1);
	}
	rep(i,cnt)if(tmp[i].first>tmp[i].second)swap(tmp[i].first,tmp[i].second);
	sort(tmp+1,tmp+cnt+1);
	int now=1;
	for(const auto&E:S)
	{
		int x=E.first,y=E.second;
		// printf("%d %d\n",x,y);
		for(;now<=cnt&&tmp[now]<E;now++);
		if(now<=cnt&&E==tmp[now])
		{
			s.insert(E);
			now++;
		}
		else par[find(x)]=find(y);
	}
}
void modi(int x,int y)
{
	if(x>y)swap(x,y);
	if(S.find(mp(x,y))==S.end())S.insert(mp(x,y)),s.insert(mp(x,y));else S.erase(mp(x,y)),s.erase(mp(x,y));
}
int q[N];
void query(int x,int y)
{
	last=0;
	for(const auto&E:s)
	{
		int a=find(E.first),b=find(E.second);
		g[a].pb(b);g[b].pb(a);
	}
	int t;in[q[t=1]=find(x)]=1;
	rep(i,t)
	{
		int u=q[i];
		if(u==find(y))last=1;
		for(auto j:g[u])if(!in[j])in[q[++t]=j]=1;
	}
	rep(i,t)in[q[i]]=0;
	for(const auto&E:s)
	{
		int a=find(E.first),b=find(E.second);
		g[a].clear();g[b].clear();
	}
	putchar(last+'0');
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,m)scanf("%d%d%d",&opt[i],&x[i],&y[i]);
	rep(i,n)par[i]=i;
	last=0;
	rep(i,m)
	{
		int a=(x[i]+last-1)%n+1,b=(y[i]+last-1)%n+1;
		// printf("%d %d %d\n",opt[i],a,b);
		if(opt[i]==1)modi(a,b);
		else query(a,b);
		if(i%K==0&&i<m)rebuild(i);
	}
	puts("");
	return 0;
}