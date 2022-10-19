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
#define ll int
#define N 200010
#define M 300010
#define Q 500010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,m,q,p[N],fa[N],cnt[N],smed[Q],rep[Q];
ll getf(ll x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
bool erz[M],vis[N];
set<ll> st[N];
vector<ll> pat;
vector<pair<ll,ll> > ed,qry,vt[N];
void dfs(ll x)
{
	vis[x]=true;
	pat.push_back(x);
	ll i;
	for(i=0;i<vt[x].size();++i)
	{
		if((!erz[vt[x][i].S])&&(!vis[vt[x][i].F]))
		{
			dfs(vt[x][i].F);
		}
	}
	return;
}
int main(){
	ll i,j,x,y;
	n=rint(),m=rint(),q=rint();
	for(i=0;i<n;++i)
	{
		cnt[i]=1;
		fa[i]=i;
		p[i]=rint()-1;
	}
	for(i=0;i<m;++i)
	{
		x=p[rint()-1],y=p[rint()-1];
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
		ed.push_back(make_pair(x,y));
	}
	for(i=0;i<q;++i)
	{
		x=rint(),y=rint()-1;
		qry.push_back(make_pair(x,x==1?p[y]:y));
		if(x==2)
		{
			erz[y]=true;
		}
	}
	for(i=0;i<m;++i)
	{
		if(!erz[i])
		{
			x=getf(ed[i].F),y=getf(ed[i].S);
			cnt[x]+=cnt[y];
			cnt[y]=0;
			fa[y]=x;
		}
	}
	for(i=q-1;i>=0;--i)
	{
		smed[i]=-1;
		if(qry[i].F==2)
		{
			x=ed[qry[i].S].F,y=ed[qry[i].S].S;
			if(getf(x)!=getf(y))
			{
				x=getf(x),y=getf(y);
				if(cnt[x]<cnt[y])
				{
					swap(x,y);
				}
				smed[i]=y;
				cnt[x]+=cnt[y];
				cnt[y]=0;
				fa[y]=x;
				rep[i]=x;
			}
		}
	}
	for(i=0;i<n;++i)
	{
		st[getf(i)].insert(-i);
		fa[i]=getf(i);
	}
	memset(erz,false,sizeof(erz));
	for(i=0;i<q;++i)
	{
		if(qry[i].F==1)
		{
			if(st[fa[qry[i].S]].size()==0)
			{
				rout(0);
			}
			else
			{
				rout(-(*st[fa[qry[i].S]].begin())+1);
				st[fa[qry[i].S]].erase(st[fa[qry[i].S]].begin());
			}
			putchar('\n');
		}
		else if(smed[i]!=-1)
		{
			erz[qry[i].S]=true;
			for(j=0;j<pat.size();++j)
			{
				vis[pat[j]]=false;
			}
			pat.clear();
			dfs(smed[i]);
			for(j=0;j<pat.size();++j)
			{
				fa[pat[j]]=smed[i];
				if(st[rep[i]].find(-pat[j])!=st[rep[i]].end())
				{
					st[rep[i]].erase(-pat[j]);
					st[smed[i]].insert(-pat[j]);
				}
			}
		}
		else
		{
			erz[qry[i].S]=true;
		}
	}
	return 0;
}