#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::pair<ll,ll> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
std::multiset<ll>s[MAXN],res;
ll val[MAXN],sum[MAXN], tag[MAXN];
int fa[MAXN],deg[MAXN];
void del_ctrb(int x)
{
	if(!x)return;
	if(s[x].size())
	{
		res.erase(res.lower_bound(tag[x]+*s[x].begin()));
		res.erase(res.lower_bound(tag[x]+*--s[x].end()));
	}
}
void add_ctrb(int x)
{
	if(!x)return;
	if(s[x].size())res.insert(tag[x]+*s[x].begin()),res.insert(tag[x]+*--s[x].end());
}
void eraseS(int x,int y){if(y)s[y].erase(s[y].lower_bound(sum[x]));}
void insertS(int x,int y){if(y)s[y].insert(sum[x]);}
std::vector<int>g[MAXN];
int main()
{
	int n=read(),q=read();
	for(int i=1;i<=n;++i)val[i]=read(),tag[i]=0;
	for(int i=1;i<=n;++i)fa[i]=read(),g[i].push_back(fa[i]),g[fa[i]].push_back(i);
	for(int u=1;u<=n;++u)
	{
		ll k=val[u]/(g[u].size()+1);
		sum[fa[u]]+=k;
		sum[u]+=val[u]-k*g[u].size();
		tag[u]=k;
		deg[u]=g[u].size()+1;
	}
	for(int u=1;u<=n;++u)
	{
		for(auto v:g[u])
			if(v!=fa[u])s[u].insert(sum[v]);
		add_ctrb(u);
	}
	while(q--)
	{
		int t=read();
		if(t==1)
		{
			int u=read(),v=read(),f=fa[u];
			//cut the edge (u,f)
			del_ctrb(fa[fa[f]]),del_ctrb(fa[f]),del_ctrb(f);
			eraseS(fa[f],fa[fa[f]]),eraseS(f,fa[f]),eraseS(u,f);
			ll delta=val[f]/(deg[f]-1)-val[f]/deg[f];
			sum[fa[f]]+=delta,tag[f]+=delta;
			sum[f]=sum[f]- (val[f]-val[f]/deg[f]*(deg[f]-1))+ (val[f]-val[f]/(deg[f]-1)*(deg[f]-2));
			sum[f]-=val[u]/deg[u];
			--deg[f];
			insertS(fa[f],fa[fa[f]]),insertS(f,fa[f]);
			add_ctrb(f),add_ctrb(fa[f]),add_ctrb(fa[fa[f]]);
			//add the edge(u,v)
			del_ctrb(fa[fa[v]]),del_ctrb(fa[v]),del_ctrb(v);
			eraseS(fa[v],fa[fa[v]]),eraseS(v,fa[v]);
			delta=val[v]/(deg[v]+1)-val[v]/deg[v];
			sum[fa[v]]+=delta,tag[v]+=delta;
			sum[v]=sum[v]- (val[v]-val[v]/deg[v]*(deg[v]-1))+ (val[v]-val[v]/(deg[v]+1)*deg[v]);
			sum[v]+=val[u]/deg[u];
			++deg[v];
			insertS(fa[v],fa[fa[v]]),insertS(v,fa[v]),insertS(u,v);
			add_ctrb(v),add_ctrb(fa[v]),add_ctrb(fa[fa[v]]);
			fa[u]=v;
		}
		else if(t==2)
		{
			int u=read();
			printf("%lld\n",sum[u]+tag[fa[u]]);
		}
		else printf("%lld %lld\n",*res.begin(),*--res.end());
	}
	return 0;
}