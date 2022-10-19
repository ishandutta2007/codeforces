#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 100010
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
ll n,m,fa[N],ans[N],dep[N],sonsz[N],hgsn[N];
string nams[N];
vector<ll> vt[N],rts;
vector<pair<ll,ll> > qry[N];
map<string,ll> cnts[2*N];
char buf[25];
void predfs(ll x,ll d)
{
	ll i,mx=0;
	sonsz[x]=1;
	dep[x]=d;
	for(i=0;i<vt[x].size();++i)
	{
		predfs(vt[x][i],d+1);
		sonsz[x]+=sonsz[vt[x][i]];
		if(mx<sonsz[vt[x][i]])
		{
			mx=sonsz[vt[x][i]];
			hgsn[x]=vt[x][i];
		}
	}
	return;
}
void upddfs(ll x,ll v)
{
	cnts[dep[x]][nams[x]]+=v;
	if(cnts[dep[x]][nams[x]]==0)
	{
		cnts[dep[x]].erase(cnts[dep[x]].find(nams[x]));
	}
	ll i;
	for(i=0;i<vt[x].size();++i)
	{
		upddfs(vt[x][i],v);
	}
	return;
}
void dfs(ll x,bool tp)
{
	ll i;
	for(i=0;i<vt[x].size();++i)
	{
		if(vt[x][i]!=hgsn[x])
		{
			dfs(vt[x][i],true);
		}
	}
	if(hgsn[x]!=-1)
	{
		dfs(hgsn[x],false);
	}
	for(i=0;i<vt[x].size();++i)
	{
		if(vt[x][i]!=hgsn[x])
		{
			upddfs(vt[x][i],1);
		}
	}
	++cnts[dep[x]][nams[x]];
	for(i=0;i<qry[x].size();++i)
	{
		ans[qry[x][i].S]=cnts[qry[x][i].F+dep[x]].size();
	}
	if(tp)
	{
		upddfs(x,-1);
	}
	return;
}
int main(){
	ll i,x,y;
	n=rint();
	for(i=0;i<n;++i)
	{
		scanf("%s",&buf);
		fa[i]=rint()-1;
		nams[i]=buf;
		if(fa[i]==-1)
		{
			rts.push_back(i);
		}
		else
		{
			vt[fa[i]].push_back(i);
		}
	}
	memset(hgsn,-1,sizeof(hgsn));
	m=rint();
	for(i=0;i<m;++i)
	{
		x=rint()-1,y=rint();
		qry[x].push_back(make_pair(y,i));
	}
	for(i=0;i<rts.size();++i)
	{
		predfs(rts[i],0);
		dfs(rts[i],true);
	}
	for(i=0;i<m;++i)
	{
		rout(ans[i]),putchar('\n');
	}
	return 0;
}