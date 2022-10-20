#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,m,mod,fa[N],cnt[N];
ll ksm(ll x,ll y)
{
	ll i,ret=1;
	while(y)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
ll getf(ll x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
void merg(ll x,ll y)
{
	x=getf(x),y=getf(y);
	if(x==y)
	{
		return;
	}
	fa[x]=y;
	cnt[y]+=cnt[x];
	cnt[x]=0;
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld%lld",&n,&m,&mod);
	for(i=0;i<n;i++)
	{
		fa[i]=i;
		cnt[i]=1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		merg(x,y);
	}
	vector<ll> allv;
	for(i=0;i<n;i++)
	{
		if(cnt[i]>0)
		{
			allv.push_back(cnt[i]);
		}
	}
	if(allv.size()==1)
	{
		printf("%lld\n",1%mod);
	}
	else
	{
		ll ans=ksm(n,allv.size()-2);
		for(i=0;i<allv.size();i++)
		{
			ans=(ans*allv[i])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}