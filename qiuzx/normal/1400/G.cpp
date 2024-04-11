#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;\
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
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
ll fact[N],inv[N];
ll GetC(ll x,ll y)
{
	if(x<y||x<0||y<0)
	{
		return 0;
	}
	return (fact[x]*((inv[y]*inv[x-y])%mod))%mod;
}
ll n,m,l[N],r[N],dif[N],sum[N][45],ans=0;
bool vis[N];
vector<pair<ll,ll> > ed;
ll getval(ll mask)
{
	ll i,ml=1,mr=n,sz=0;
	for(i=0;i<m;i++)
	{
		vis[ed[i].F]=vis[ed[i].S]=false;
	}
	for(i=0;i<m;i++)
	{
		if(mask&(1<<i))
		{
			ml=max(ml,l[ed[i].F]);
			mr=min(mr,r[ed[i].F]);
			if(!vis[ed[i].F])
			{
				sz++;
			}
			vis[ed[i].F]=true;
			ml=max(ml,l[ed[i].S]);
			mr=min(mr,r[ed[i].S]);
			if(!vis[ed[i].S])
			{
				sz++;
			}
			vis[ed[i].S]=true;
		}
	}
	if(ml>mr)
	{
		return 0;
	}
	//cout<<ml<<" "<<mr<<endl;
	return (sum[mr][sz]+mod-sum[ml-1][sz])%mod;
}
int main(){
	ll i,j,x,y;
	fact[0]=inv[0]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=ksm(fact[i],mod-2);
	}
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		dif[r[i]+1]--;
		dif[l[i]]++;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		ed.push_back(make_pair(x,y));
	}
	for(i=1;i<=n;i++)
	{
		dif[i]+=dif[i-1];
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=min(i,2*m);j++)//choose i people with j of them already selected (guarenteed that these j people have lj<=i<=rj)
		{
			sum[i][j]=(i==0?0:sum[i-1][j]+GetC(dif[i]-j,i-j))%mod;
			//cout<<i<<" "<<j<<": "<<sum[i][j]<<endl;
		}
	}
	for(i=0;i<(1<<m);i++)
	{
		x=getval(i);
		if(__builtin_popcount(i)%2==0)
		{
			ans=(ans+x)%mod;
		}
		else
		{
			ans=(ans+mod-x)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}