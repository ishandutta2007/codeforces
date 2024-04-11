#include<iostream>
#include<cstdio>
typedef long long ll;
void work()
{
	ll l1,r1,l2,r2;
	std::cin>>l1>>r1>>l2>>r2;
	if(l1!=r2)std::cout<<l1<<" "<<r2<<std::endl;
	else std::cout<<r1<<" "<<l2<<std::endl;
}
int main()
{
	ll n;
	std::cin>>n;
	while(n--)work();
	return 0;
}