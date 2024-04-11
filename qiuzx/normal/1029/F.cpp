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
#define N 100010
using namespace std;
ll a,b,ans=LINF;
vector<ll> fac[2];
bool check(ll x,ll y)
{
	ll p0=upper_bound(fac[0].begin(),fac[0].end(),x)-fac[0].begin()-1,p1=upper_bound(fac[1].begin(),fac[1].end(),x)-fac[1].begin()-1;
	if(p0>=0&&a/fac[0][p0]<=y)
	{
		return true;
	}
	if(p1>=0&&b/fac[1][p1]<=y)
	{
		return true;
	}
	return false;
}
int main(){
	ll i;
	cin>>a>>b;
	for(i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			fac[0].push_back(i);
			fac[0].push_back(a/i);
		}
	}
	for(i=1;i*i<=b;i++)
	{
		if(b%i==0)
		{
			fac[1].push_back(i);
			fac[1].push_back(b/i);
		}
	}
	sort(fac[0].begin(),fac[0].end());
	sort(fac[1].begin(),fac[1].end());
	for(i=1;i*i<=a+b;i++)
	{
		if((a+b)%i==0)
		{
			if(check(i,(a+b)/i))
			{
				ans=min(ans,2*(i+(a+b)/i));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}