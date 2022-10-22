#include<iostream>
#include<cstdio>
typedef long long ll;
bool ans=0;
ll b,k;
int main()
{
	std::cin>>b>>k;
	if(b&1)
	{
		ll t;
		for(ll i=1;i<=k;++i)
		{
			std::cin>>t;
			ans^=(t&1);
		}
	}
	else
	{
		ll t;
		for(ll i=1;i<=k;++i)
			std::cin>>t;
		ans=t&1;
	}
	if(ans)std::cout<<"odd";
	else std::cout<<"even";
	return 0;
}