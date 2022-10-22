#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
struct day
{
	ll min,max;
}a[10001];
ll n,sum;
ll start()
{
	std::cin>>n>>sum;
	ll cnt1=0,cnt2=0;
	for(ll i=1;i<=n;++i)
	{
		std::cin>>a[i].min>>a[i].max;
		cnt1+=a[i].min;
		cnt2+=a[i].max;
	}
	if(cnt1<=sum&&sum<=cnt2)return cnt1;
	else return -1;
}
int main()
{
	ll t=start(),k;
	if(t>=0)
	{
		puts("YES");
		for(ll i=1;i<=n;++i)
		{
			k=sum-t;
			if(k>(a[i].max-a[i].min))
			{
				t+=a[i].max-a[i].min;
				printf("%lld ",a[i].max);
			}
			else
			{
				printf("%lld ",k+a[i].min);
				t=sum;
			}
		}
	}
	else puts("NO");
	return 0;
}