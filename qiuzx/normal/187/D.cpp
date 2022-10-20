#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,g,r,t,a[N],sum[N],dp[N],qu[N],nxt[N],q;
set<pair<ll,ll> > st;
ll gm(ll x,ll m)
{
	x%=m;
	while(x<0)
	{
		x+=m;
	}
	return x;
}
void update(ll x,ll l,ll r)
{
	pair<ll,ll> tar=make_pair(l,0);
	set<pair<ll,ll> >::iterator a;
	while(!st.empty())
	{
		a=st.lower_bound(tar);
		if(a==st.end())
		{
			return;
		}
		if(a->F>r)
		{
			return;
		}
		nxt[a->S]=x;
		st.erase(a);
	}
	return;
}
int main(){
	ll i,x,y,ts=0,ans;
	cin>>n>>g>>r;
	t=g+r;
	for(i=0;i<=n;i++)
	{
		cin>>a[i];
		sum[i+1]=sum[i]+a[i];
	}
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>qu[i];
		st.insert(make_pair(gm(-qu[i],t),n+i));
	}
	memset(dp,0,sizeof(dp));
	for(i=0;i<=n+q+1;i++)
	{
		nxt[i]=n+1;
	}
	for(i=0;i<n;i++)
	{
		ts+=a[i];
		x=gm(ts+1,t);
		y=gm(ts+r,t);
		if(x<=y)
		{
			update(i+1,x,y);
		}
		else
		{
			update(i+1,x,t-1);
			update(i+1,0,y);
		}
		st.insert(make_pair(gm(ts,t),i+1));
	}
	for(i=n;i>=0;i--)
	{
		dp[i]=dp[nxt[i]]+sum[nxt[i]]-sum[i];
		if(nxt[i]!=n+1)
		{
			dp[i]+=t-gm(sum[nxt[i]]-sum[i],t);
		}
	}
	for(i=1;i<=q;i++)
	{
		ans=dp[nxt[n+i]]+sum[nxt[n+i]]+qu[i];
		if(nxt[n+i]!=n+1)
		{
			ans+=t-gm(sum[nxt[n+i]]+qu[i],t);
		}
		cout<<ans<<endl;
	}
	return 0;
}