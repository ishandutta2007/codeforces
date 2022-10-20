#include <bits/stdc++.h>
#define N 200010
#define F first
#define S second
typedef long long ll;
using namespace std;
ll n,k,l,r,mid,hs[N],nd[N],tem[N];
priority_queue<pair<ll,ll> > pq,beg; 
bool check(ll x)
{
	ll i,t,pre,v;
	pq=beg;
	if(pq.empty())
	{
		return true;
	}
	for(i=0;i<n;i++)
	{
		tem[i]=hs[i];
	}
	for(i=0;i<k-1;i++)
	{
		t=-pq.top().F;
		v=pq.top().S;
		pq.pop();
		if(t-i<0)
		{
			return false;
		}
		tem[v]+=x;
		t=tem[v]/nd[v];
		if(t-i-1<0)
		{
			return false;
		}
		pq.push(make_pair(-t,v));
	}
	while(!pq.empty())
	{
		t=-pq.top().F;
		if(t<k-1)
		{
			return false;
		}
		pq.pop();
	}
	return true;
}
int main(){
	int i;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>hs[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>nd[i];
	}
	for(i=0;i<n;i++)
	{
		if(hs[i]/nd[i]>=k-1)
		{
			continue;
		}
		beg.push(make_pair(-(hs[i]/nd[i]),i));
	}
	l=0;
	r=2e12;
	if(!check(r))	
	{
		cout<<-1<<endl;
		return 0;
	}
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}