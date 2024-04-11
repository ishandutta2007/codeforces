#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011,V = 100000;
pll a[MAXN];//a[u]= px+qy
std::vector<int>g[MAXN];
void dfs(int u,int fa,pll part,pll sum)
{
	//printf("u=%d,fa=%d,part=(%d,%d),sum=(%d,%d)\n",u,fa,part.first,part.second,sum.first,sum.second);
	if(g[u].size()==1){a[u]=part;return;}
	int t=int(g[u].size())-1;
	a[u]=pll(part.first-sum.first*t,part.second-sum.second*t);
	for(auto v:g[u])
		if(v!=fa)dfs(v,u,sum,part);
}
std::set<int>ban;
ll low_div(ll a,ll b)//b>0
{
	return floor(double(a)/b);
}
ll up_div(ll a,ll b)//b>0
{
	return ceil(double(a)/b);
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)g[i].clear(),a[i]=pll(0,0);
		for(int i=1;i<n;++i){int u=read(),v=read();g[u].emplace_back(v),g[v].emplace_back(u);}
		for(int u=1;u<=n;++u)
			if(g[u].size()==1)
			{
				int v=g[u][0];
				a[u]=pll(1,0),a[v]=pll(0,1);
				int d=int(g[v].size())-1;
				for(auto t:g[v])
					if(t!=u)
					{
						dfs(t,v,pll(1,0),pll(d,1));
					}
				break;
			}
		ban.clear();
		//let x=1
		ll low=-V,up=V;
		for(int u=1;u<=n;++u)
		{
			ll p=a[u].first,q=a[u].second;
			if(!q)continue;
			if(p%q==0)ban.insert(-p/q);
			if(q>0)umax(low,up_div(-V-p,q)),umin(up,low_div(V-p,q));
			else umax(low,up_div(V-p,q)),umin(up,low_div(-V-p,q));
		}
		ll y=low;
		while(ban.count(y))++y;
		for(int i=1;i<=n;++i)printf("%lld ",a[i].first+a[i].second*y);
		puts("");
	}
	return 0;
}