#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
ll n;
struct one
{
	ll x,y;
}amax,amin,tmp;
int main()
{
	std::cin>>n;
	std::cin>>tmp.x>>tmp.y;
	amin=tmp;
	for(ll i=2;i<=n;++i)
	{
		std::cin>>tmp.x>>tmp.y;
		if(tmp.x<amin.x)amin=tmp;
		else if(tmp.x==amin.x&&tmp.y<amin.y)amin.y=tmp.y;
	}
	std::cin>>tmp.x>>tmp.y;
	amax=tmp;
	for(ll i=2;i<=n;++i)
	{
		std::cin>>tmp.x>>tmp.y;
		if(tmp.x>amax.x)amax=tmp;
		else if(tmp.x==amax.x&&tmp.y>amax.y)amax.y=tmp.y;
	}
	std::cout<<(amax.x+amin.x)<<" "<<amax.y+amin.y;
	return 0;
}