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
#define N 500010
using namespace std;
ll n,k,a[N],b[N],dp[N],ans=0;
vector<ll> pos;
void upd(ll x,ll v)
{
	x++;
	while(x<N)
	{
		if(v==0)
		{
			dp[x]=v;
		}
		else
		{
			dp[x]=max(dp[x],-v);
		}
		x+=(x&(-x));
	}
	return;
}
ll query(ll x)
{
	ll ret=0;
	x++;
	while(x>0)
	{
		ret=max(ret,dp[x]);
		x-=(x&(-x));
	}
	return ret;
}
vector<ll> diff(vector<ll> p)
{
	vector<ll> tt=p;
	sort(tt.begin(),tt.end());
	tt.erase(unique(tt.begin(),tt.end()),tt.end());
	ll i;
	for(i=0;i<p.size();i++)
	{
		p[i]=lower_bound(tt.begin(),tt.end(),p[i])-tt.begin();
	}
	return p;
}
ll solve(ll l,ll r,ll lv,ll rv)
{
	ll i,res;
	pos.clear();
	for(i=l;i<=r;i++)
	{
		if(lv<=a[i]&&a[i]<=rv)
		{
			pos.push_back(a[i]);
		}
	}
	pos=diff(pos);
	if(pos.empty())
	{
		return r-l+1;
	}
	for(i=0;i<pos.size();i++)
	{
		upd(pos[i],0);
	}
	for(i=0;i<pos.size();i++)
	{
		upd(pos[i],-query(pos[i])-1);
		upd(pos[i],-1);
	}
	res=0;
	for(i=0;i<pos.size();i++)
	{
		res=max(res,query(pos[i]));
	}
	return r-l+1-res;
}
int main(){
	ll i;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]-=i;
	}
	a[0]=-LINF;
	a[n+1]=LINF;
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&b[i]);
	}
	b[0]=0;
	b[k+1]=n+1;
	for(i=0;i<=k;i++)
	{
		if(a[b[i]]>a[b[i+1]])
		{
			puts("-1");
			return 0;
		}
		if(b[i]+1<b[i+1])
		{
			ans+=solve(b[i]+1,b[i+1]-1,a[b[i]],a[b[i+1]]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}