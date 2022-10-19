#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define N 100010
using namespace std;
ll n,ans=0;
vector<ll> divi,app,a;
ll ksm(ll x,ll y)
{
	if(x==0)
	{
		return 0;
	}
	if(y==0)
	{
		return 1;
	}
	ll ret=ksm(x,y>>1);
	ret=(ret*ret)%mod;
	if(y%2==1)
	{
		ret=(ret*x)%mod;
	}
	return ret;
}
void getdivi(ll x)
{
	divi.clear();
	ll i;
	for(i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			divi.push_back(i);
			if(i*i!=x)
			{
				divi.push_back(x/i);
			}
		}
	}
	return;
}
void getapp()
{
	ll i,ts1,ts2;
	app.clear();
	app.push_back(0);
	for(i=0;i<divi.size();i++)
	{
		app.push_back(a.size()-(lower_bound(a.begin(),a.end(),divi[i])-a.begin()));
	}
	return;
}
int main(){
	ll i,x,j,ts1,ts2;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(i=100000;i>=1;i--)//maximum value (guaranteed to appear to avoid counting mutiple times)
	{
		getdivi(i);
		sort(divi.begin(),divi.end());
		reverse(divi.begin(),divi.end());
		getapp();
		ts1=ts2=1;
		if(app.size()<=1)
		{
			ts1=0;
		}
		for(j=1;j<app.size();j++)
		{
			ts1=(ts1*ksm(app.size()-j,app[j]-app[j-1]))%mod;
		}
		app[1]=0;
		if(app.size()<=2)
		{
			ts2=0;
		}
		for(j=2;j<app.size();j++)
		{
			ts2=(ts2*ksm(app.size()-j,app[j]-app[j-1]))%mod;
		}
		ans=(ans+ts1-ts2+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}