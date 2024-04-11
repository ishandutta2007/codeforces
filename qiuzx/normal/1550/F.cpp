//ANMHLIJKTJIY!
#pragma GCC optimize(2)
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
ll n,q,s,d,dist[N],a[N];
set<ll> pts,lft;
priority_queue<pair<ll,ll> > pq;
ll getdist(ll x)
{
	set<ll>::iterator it=pts.lower_bound(x);
	ll ret=LINF;
	if(it!=pts.end())
	{
		ret=min(ret,abs((*it)-x));
	}
	if(it!=pts.begin())
	{
		it--;
		ret=min(ret,abs((*it)-x));
	}
	return ret;
}
void add_node(ll id,ll di)
{
	dist[id]=di;
	pts.insert(a[id]-d);
	pts.insert(a[id]+d);
	lft.erase(lft.lower_bound(id));
	return;
}
int main(){
	ll i,x,y,nxt;
	scanf("%lld%lld%lld%lld",&n,&q,&s,&d);
	s--;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		lft.insert(i);
	}
	memset(dist,63,sizeof(dist));
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		x=pq.top().S;
		y=-pq.top().F;
		pq.pop();
		if(dist[x]<=y)
		{
			continue;
		}
		nxt=lower_bound(a,a+n,a[x]-d)-a;
		set<ll>::iterator it=lft.lower_bound(nxt);
		if(it!=lft.end())
		{
			nxt=*it;
			pq.push(make_pair(-max(y,abs(a[nxt]-(a[x]-d))),nxt));
		}
		if(it!=lft.begin())
		{
			it--;
			nxt=*it;
			pq.push(make_pair(-max(y,abs(a[nxt]-(a[x]-d))),nxt));
		}
		nxt=lower_bound(a,a+n,a[x]+d)-a;
		it=lft.lower_bound(nxt);
		if(it!=lft.end())
		{
			nxt=*it;
			pq.push(make_pair(-max(y,abs(a[nxt]-(a[x]+d))),nxt));
		}
		if(it!=lft.begin())
		{
			it--;
			nxt=*it;
			pq.push(make_pair(-max(y,abs(a[nxt]-(a[x]+d))),nxt));
		}
		add_node(x,y);
		it=lft.lower_bound(x);
		if(it!=lft.end())
		{
			nxt=*it;
			pq.push(make_pair(-max(y,getdist(a[nxt])),nxt));
		}
		if(it!=lft.begin())
		{
			it--;
			nxt=*it;
			pq.push(make_pair(-max(y,getdist(a[nxt])),nxt));
		}
	}
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		if(dist[x]<=y)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}