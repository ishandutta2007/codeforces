#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
ll max1,max2,min1,min2,n;
ll a[100001];
ll min(ll a,ll b)
{
	return a<b?a:b;
}
int main()
{
	std::cin>>n;
	ll t,cnt=0;
	for(ll i=1;i<=n;++i)
	{
		std::cin>>t;
		++a[t];
	}
	for(ll i=100000;i>=1;--i)
	{
		if(a[i])
		{
			
			++cnt;
			if(cnt==1)max1=i;
			else max2=i;
			if(a[i]>1)
			{
				++cnt;
				max2=i;
			}
			if(cnt>=2)break;
		}
	}
	cnt=0;
	for(ll i=1;i<=100000;++i)
	{
		if(a[i])
		{
			++cnt;
			if(cnt==1)min1=i;
			else min2=i;
			if(a[i]>1)
			{
				++cnt;
				min2=i;
			}
			if(cnt>=2)break;
		}
	}
	std::cout<<min(max1-min2,max2-min1);
	return 0;
}