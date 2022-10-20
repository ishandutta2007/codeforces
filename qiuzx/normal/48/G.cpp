#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200000
using namespace std;
ll n,st=-1,sz[N],vali[N],dist[N],par[N],valo[N],valc[N],sumsz[N],sumtms[N],df[N];
vector<pair<ll,ll> > vt[N];
vector<ll> cyc,dc;
bool vis[N],isc[N],fdcyc=false;
ll getdist(ll x,ll y)
{
	pair<ll,ll> p=make_pair(y,-1);
	ll pos=lower_bound(vt[x].begin(),vt[x].end(),p)-vt[x].begin();
	return vt[x][pos].S;
}
void dfs(ll x,ll lst)
{
	vis[x]=true;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i].F])
		{
			dfs(vt[x][i].F,x);
		}
		else if(vt[x][i].F!=lst)
		{
			fdcyc=true;
			st=vt[x][i].F;
			isc[x]=true;
			cyc.push_back(x);
			return;
		}
		if(fdcyc)
		{
			isc[x]=true;
			cyc.push_back(x);
			if(x==st)
			{
				fdcyc=false;
			}
			return;
		}
	}
	return;
}
void dfs2(ll x,ll lst,ll d)
{
	ll i;
	dist[x]=d;
	sz[x]=1;
	vali[x]=0;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst&&!isc[vt[x][i].F])
		{
			dfs2(vt[x][i].F,x,d+vt[x][i].S);
			sz[x]+=sz[vt[x][i].F];
			vali[x]+=vali[vt[x][i].F]+sz[vt[x][i].F]*vt[x][i].S;
		}
	}
	return;
}
void dfs3(ll x,ll lst,ll lval,ll beg)
{
	ll i;
	par[x]=beg;
	valo[x]=0;
	if(lst!=-1)
	{
		valo[x]=valo[lst]+(sz[beg]-sz[lst])*lval;
		valo[x]+=vali[lst]-vali[x]-sz[x]*lval+(sz[lst]-sz[x])*lval;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst&&!isc[vt[x][i].F])
		{
			dfs3(vt[x][i].F,x,vt[x][i].S,beg);
		}
	}
	return;
}
int main(){
	ll i,x,y,z,mv=0,l,r,tot;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
	}
	for(i=0;i<n;i++)
	{
		sort(vt[i].begin(),vt[i].end());
	}
	dfs(0,-1);
	for(i=0;i<cyc.size();i++)
	{
		dfs2(cyc[i],-1,0);//calculate in a tree
		dfs3(cyc[i],-1,0,cyc[i]);
		mv+=vali[cyc[i]];
	}
	/*
	valc[i]+=vali[j]+sz[j]*min(abs(dist[i]-dist[j]),total-abs(dist[i]-dist[j]));
	sum(vali[j]):OK
	1)2*abs(dist[i]-dist[j])<=total:
		a)j<i:
			sz[j]*dist[i]-sz[j]*dist[j]
			sum(sz[j])*dist[i]-sum(sz[j]*dist[j])
		b)j>i:
			sz[j]*dist[j]-sz[j]*dist[i]
			sum(sz[j]*dist[j])-sum(sz[j])*dist[i]
	2)2*abs(dist[i]-dist[j])>total:
		a)j<i:
			sz[j]*(total-dist[i]+dist[j])
			sum(sz[j])*(total-dist[i])+sum(sz[j]*dist[j])
		b)j>i:
			sz[j]*(total+dist[i]-dist[j])
			sum(sz[j])*(total+dist[i])-sum(sz[j]*dist[j])
	*/
	//df[x]->w[1,2]+w[2,3]+...+w[x-1,x]
	//sumsz[x]->sz[1]+sz[2]+...+sz[x]  sumtms[x]->sz[1]*df[1]+sz[2]*df[2]+...+sz[x]*df[x]
	df[0]=df[1]=sumsz[0]=sumtms[0]=sumtms[1]=0;
	sumsz[1]=sz[cyc[0]];
	dc.push_back(0);
	for(i=1;i<cyc.size();i++)
	{
		df[i+1]=df[i]+getdist(cyc[i-1],cyc[i]);
		dc.push_back(df[i+1]);
		sumsz[i+1]=sumsz[i]+sz[cyc[i]];
		sumtms[i+1]=sumtms[i]+sz[cyc[i]]*df[i+1];
	}
	tot=df[cyc.size()]+getdist(cyc[0],cyc[cyc.size()-1]);
	for(i=0;i<cyc.size();i++)
	{
		valc[cyc[i]]=mv-vali[cyc[i]];
		l=lower_bound(dc.begin(),dc.end(),df[i+1]-tot/2)-dc.begin();
		r=upper_bound(dc.begin(),dc.end(),df[i+1]+tot/2)-dc.begin()-1;
		//1a->l~i-1
		valc[cyc[i]]+=(sumsz[i]-sumsz[l])*df[i+1]-(sumtms[i]-sumtms[l]);
		//1b->i+1~r
		valc[cyc[i]]+=(sumtms[r+1]-sumtms[i+1])-(sumsz[r+1]-sumsz[i+1])*df[i+1];
		//2a->0~l-1
		valc[cyc[i]]+=(sumsz[l]-sumsz[0])*(tot-df[i+1])+(sumtms[l]-sumtms[0]);
		//2b->r+1~cyc.size()-1
		valc[cyc[i]]+=(sumsz[cyc.size()]-sumsz[r+1])*(tot+df[i+1])-(sumtms[cyc.size()]-sumtms[r+1]);
	}
	for(i=0;i<n;i++)
	{
		valc[i]=valc[par[i]]+(n-sz[par[i]])*dist[i];
	}
	for(i=0;i<n;i++)
	{
		printf("%lld ",vali[i]+valo[i]+valc[i]);
	}
	puts("");
	return 0;
}