#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n,k,a,b;

ll ans1=1e18,ans2;

void cal(ll st)
{
	ll ed;
	for(int i=1;i<=n;i++)
	{
		ed=(i-1)*k+b+1;
		if(ed<st)
			ed+=n*k;
		ll t=ed-st==0?n*k:ed-st;
		ans1=min(ans1,n*k/__gcd(n*k,t));
		ans2=max(ans2,n*k/__gcd(n*k,t));
		ed=i*k-b+1;
		if(ed<st)
			ed+=n*k;
		t=ed-st==0?n*k:ed-st;
		ans1=min(ans1,n*k/__gcd(n*k,t));
		ans2=max(ans2,n*k/__gcd(n*k,t));
	}
}

int main()
{
	scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
	cal(a+1);
	cal(k-a+1);
	printf("%lld %lld",ans1,ans2);
}