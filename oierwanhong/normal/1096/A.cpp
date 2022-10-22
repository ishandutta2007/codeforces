#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
int main()
{
	ll t,l,r;
	std::cin>>t;
	while(t--)
	{
		std::cin>>l>>r;
		if(r&1)std::cout<<(r>>1)<<" "<<r-1<<std::endl;
		else std::cout<<(r>>1)<<" "<<r<<std::endl;
	}
	return 0;
}