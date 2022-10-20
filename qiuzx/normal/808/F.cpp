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
#define N 110
using namespace std;
vector<pair<pair<ll,ll>,ll> > vt[N];
vector<pair<pair<ll,ll>,ll> > ed,crd;
vector<pair<ll,ll> > red;
queue<ll> q;
ll vis[N],n,m,s,t,dep[N],mxo,ido,res=0;
bool trav[N][N];
bool isprime(ll x)
{
	ll i;
	if(x<2)
	{
		return false;
	}
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
void bfs(ll s)
{
	ll i,x;
	memset(dep,-1,sizeof(dep));
	dep[s]=0;
	q.push(s);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<vt[x].size();i++)
		{
			if(vt[x][i].F.S>0&&dep[vt[x][i].F.F]<0)
			{
				dep[vt[x][i].F.F]=dep[x]+1;
				q.push(vt[x][i].F.F);
			}
		}
	}
	return;
}
ll dfs(ll x,ll ed,ll val)
{
	if(x==ed)
	{
		return val;
	}
	ll i,v;
	for(i=vis[x];i<vt[x].size();i++,vis[x]++)
	{
		if(vt[x][i].F.S>0&&dep[x]<dep[vt[x][i].F.F])
		{
			v=dfs(vt[x][i].F.F,ed,min(val,vt[x][i].F.S));
			if(v>0)
			{
				vt[x][i].F.S-=v;
				vt[vt[x][i].F.F][vt[x][i].S].F.S+=v;
				return v;
			}
		}
	}
	return 0;
}
ll maxflow()
{
	ll i,x,y,z,ans=0,tt;
	n+=2;
	for(i=0;i<n;i++)
	{
		vt[i].clear();
	}
	for(i=0;i<ed.size();i++)
	{
		x=ed[i].F.F,y=ed[i].F.S,z=ed[i].S;
		vt[x].push_back(make_pair(make_pair(y,z),vt[y].size()));
		vt[y].push_back(make_pair(make_pair(x,0),vt[x].size()-1));
	}
	while(1)
	{
		bfs(s);
		if(dep[t]<0)
		{
			break;
		}
		memset(vis,0,sizeof(vis));
		while(1)
		{
			tt=dfs(s,t,LINF);
			if(tt==0)
			{
				break;
			}
			ans+=tt;
		}
	}
	n-=2;
	return ans;
}
void addnd(ll x)
{
	ll i;
	if(crd[x].S==1)
	{
		mxo=max(mxo,crd[x].F.S);
		ido=x;
		return;
	}
	for(i=0;i<x;i++)
	{
		if(trav[i][x]&&crd[i].S!=1)
		{
			if(crd[i].S&1)
			{
				red.push_back(make_pair(i,x));
			}
			else
			{
				red.push_back(make_pair(x,i));
			}
		}
	}
	return;
}
void calc(ll x)
{
	ll i,tot;
	ed.clear();
	tot=0;
	for(i=0;i<red.size();i++)
	{
		ed.push_back(make_pair(red[i],INF));
	}
	for(i=0;i<=x;i++)
	{
		if(crd[i].S!=1)
		{
			if(crd[i].S&1)
			{
				ed.push_back(make_pair(make_pair(s,i),crd[i].F.S));
			}
			else
			{
				ed.push_back(make_pair(make_pair(i,t),crd[i].F.S));
			}
			tot+=crd[i].F.S;
		}
	}
	res=max(res,tot-maxflow());
	if(mxo!=-1)
	{
		ed.clear();
		tot=0;
		for(i=0;i<red.size();i++)
		{
			if((!trav[ido][red[i].F])&&(!trav[ido][red[i].S]))
			{
				ed.push_back(make_pair(red[i],INF));
			}
		}
		for(i=0;i<=x;i++)
		{
			if(crd[i].S!=1&&(!trav[ido][i]))
			{
				if(crd[i].S&1)
				{
					ed.push_back(make_pair(make_pair(s,i),crd[i].F.S));
				}
				else
				{
					ed.push_back(make_pair(make_pair(i,t),crd[i].F.S));
				}
				tot+=crd[i].F.S;
			}
		}
		res=max(res,tot-maxflow()+mxo);
	}
	return;
}
int main(){
	ll i,j,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		crd.push_back(make_pair(make_pair(z,x),y));
	}
	sort(crd.begin(),crd.end());
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			trav[i][j]=isprime(crd[i].S+crd[j].S);
		}
	}
	mxo=-1;
	s=n;
	t=n+1;
	for(i=0;i<crd.size();i++)
	{
		addnd(i);
		calc(i);
		if(res>=m)
		{
			printf("%lld\n",crd[i].F.F);
			return 0;
		}
	}
	puts("-1");
	return 0;
}