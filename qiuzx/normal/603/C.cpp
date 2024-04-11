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
using namespace std;
ll n,k,ans=0;
ll getmex(vector<ll> v)
{
	v.push_back(INF);
	if(v[0]!=0)
	{
		return 0;
	}
	for(register int i=0;i+1<v.size();++i)
	{
		if(v[i]!=v[i+1]-1)
		{
			return v[i]+1;
		}
	}
	return INF;
}
ll getsg(ll x)
{
	if(x==1||x==3)
	{
		return 1;
	}
	if(x%2==1)
	{
		return 0;
	}
	vector<ll> v;
	v.push_back(getsg(x-1));
	v.push_back(getsg(x/2));
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	return getmex(v);
}
int main(){
	ll T,v,i,a;
	scanf("%lld%lld",&n,&k);
	v=0;
	if(k%2==0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a);
			if(a==1)
			{
				ans^=1;
			}
			else if(a==2)
			{
				ans^=2;
			}
			else
			{
				if(a%2==1)
				{
					ans^=0;
				}
				else
				{
					ans^=1;
				}
			}
		}
		if(ans==0)
		{
			puts("Nicky");
		}
		else
		{
			puts("Kevin");
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a);
			ans^=getsg(a);
		}
		if(ans==0)
		{
			puts("Nicky");
		}
		else
		{
			puts("Kevin");
		}
	}
	return 0;
}