#pragma GCC optimize(2)
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
#define N 200010
using namespace std;
ll n,m,val[N],et[N],fa[N];
vector<pair<pair<ll,ll>,ll> > frog;
priority_queue<pair<ll,ll> > pq[N],out;
ll getf(ll x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
ll getnxt(ll x)
{
	ll l=x+1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(getf(mid)>getf(x))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return getf(l);
}
void merge(ll x,ll y)
{
	ll a=getf(x),b=getf(y);
	fa[b]=a;
	return;
}
void eatnear(ll x)
{
	ll nxt=getnxt(x);
	while(nxt<n)
	{
		while(!pq[nxt].empty())
		{
			if(frog[x].F.F+frog[x].F.S<(-pq[nxt].top().F))
			{
				break;
			}
			frog[x].F.S+=pq[nxt].top().S;
			et[frog[x].S]++;
			val[frog[x].S]+=pq[nxt].top().S;
			pq[nxt].pop();
		}
		if(frog[x].F.F+frog[x].F.S<frog[nxt].F.F+frog[nxt].F.S)
		{
			break;
		}
		merge(x,nxt);
		nxt=getnxt(nxt);
	}
	return;
}
void eatfar(ll x)
{
	while(!out.empty())
	{
		if(frog[x].F.F+frog[x].F.S<(-out.top().F))
		{
			break;
		}
		et[frog[x].S]++;
		frog[x].F.S+=out.top().S;
		val[frog[x].S]+=out.top().S;
		out.pop();
	}
	return;
}
void frogdo(ll x)
{
	eatnear(x);//eat and cover those that follow before a frog
	eatfar(x);//eat those that are beyond the last frog
	return;
}
ll sld_eat(ll x)
{
	ll l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(frog[getf(mid)].F.F+frog[getf(mid)].F.S>=x)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return getf(l);
}
int main(){
	ll i,x,t;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&x,&val[i]);
		frog.push_back(make_pair(make_pair(x,val[i]),i));
		fa[i]=i;
	}
	fa[n]=n;
	sort(frog.begin(),frog.end());
	for(i=0;i<n;i++)
	{
		frogdo(i);
	}
	while(m--)
	{
		scanf("%lld%lld",&x,&t);
		i=sld_eat(x);
		if(i>=n)
		{
			out.push(make_pair(-x,t));
			continue;
		}
		if(frog[i].F.F>x)
		{
			pq[i].push(make_pair(-x,t));
			continue;
		}
		et[frog[i].S]++;
		frog[i].F.S+=t;
		val[frog[i].S]+=t;
		frogdo(i);
	}
	for(i=0;i<n;i++)
	{
		printf("%lld %lld\n",et[i],val[i]);
	}
	return 0;
}