#include<iostream>
#include<cstdio>
typedef long long ll;
ll x,y,z,a,b,c;
int main()
{
	std::cin>>x>>y>>z>>a>>b>>c;
	a-=x;
	if(a<0)
	{
		std::cout<<"NO";
		return 0;
	}
	
	a+=b;
	a-=y;
	if(a<0)
	{
		std::cout<<"NO";
		return 0;
	}
	a+=c;
	a-=z;
	if(a<0)
	{
		std::cout<<"NO";
		return 0;
	}
	std::cout<<"YES";
	return 0;
}