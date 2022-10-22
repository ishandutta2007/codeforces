#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
const ll INF=1ll<<60;
ll a[100001];
ll n;
ll cpt(ll k)
{
	return (n-k+2)*(n/k)/2;
}
int main()
{
	std::cin>>n;
	ll t=sqrt(n),cnt=0,pre;
	for(ll i=1;i<=t;++i)
	{
		if(n%i==0)a[++cnt]=cpt(i),a[++cnt]=cpt(n/i);
	}
	std::sort(a+1,a+cnt+1);
	pre=-1;
	for(ll i=1;i<=cnt;++i)
	{
		if(a[i]!=pre)std::cout<<a[i]<<" ";
		pre=a[i];
	}
	return 0;
}