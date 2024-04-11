//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
ll n,m,fa[N<<1],a[N];
vector<pair<ll,ll> > vt[N];
vector<pair<pair<ll,ll>,ll> > ed,res;
ll getf(ll x){
	return x==fa[x]?x:fa[x]=getf(fa[x]);
}
void dfs(ll x,ll lst)
{
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			if(ed[vt[x][i].S].S!=-1)
			{
				res.push_back(make_pair(make_pair(x,vt[x][i].F),__builtin_popcount(ed[vt[x][i].S].S)&1));
			}
			dfs(vt[x][i].F,x);
		}
	}
	return;
}
void dfs2(ll x,ll lst)
{
	ll i;
	a[x]=(getf(x)<n);
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			dfs2(vt[x][i].F,x);
		}
	}
	return;
}
int main(){
	ll i,j,x,y,v,T;
	T=rint();
	while(T--)
	{
		n=rint(),m=rint();
		ed.clear();
		res.clear();
		for(i=0;i<n;i++)
		{
			vt[i].clear();
		}
		for(i=0;i+1<n;i++)
		{
			x=rint()-1,y=rint()-1,v=rint();
			if(v==-1)
			{
				vt[x].push_back(make_pair(y,i));
				vt[y].push_back(make_pair(x,i));
				ed.push_back(make_pair(make_pair(x,y),-1));
			}
			else
			{
				vt[x].push_back(make_pair(y,i));
				vt[y].push_back(make_pair(x,i));
				ed.push_back(make_pair(make_pair(x,y),v));
			}
		}
		dfs(0,-1);
		for(i=0;i<m;i++)
		{
			x=rint()-1,y=rint()-1,v=rint();
			res.push_back(make_pair(make_pair(x,y),v));
		}
		for(i=0;i<n;i++)
		{
			fa[i]=i;
			fa[i+n]=i+n;
		}
		for(i=0;i<res.size();i++)
		{
			if(res[i].S==0)
			{
				fa[getf(res[i].F.F)]=getf(res[i].F.S);
				fa[getf(res[i].F.F+n)]=getf(res[i].F.S+n);
			}
			else
			{
				fa[getf(res[i].F.F)]=getf(res[i].F.S+n);
				fa[getf(res[i].F.F+n)]=getf(res[i].F.S);
			}
		}
		ll ans=0;
		for(i=0;i<n;i++)
		{
			if(getf(i)==getf(i+n))
			{
				puts("NO");
				ans=1;
				break;
			}
		}
		if(ans)
		{
			continue;
		}
		dfs2(0,-1);
		puts("YES");
		for(i=0;i<ed.size();i++)
		{
			if(ed[i].S>=0)
			{
				printf("%lld %lld %lld\n",ed[i].F.F+1,ed[i].F.S+1,ed[i].S);
			}
			else
			{
				printf("%lld %lld %lld\n",ed[i].F.F+1,ed[i].F.S+1,a[ed[i].F.F]^a[ed[i].F.S]);
			}
		}
	}
	return 0;
}