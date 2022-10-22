#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long ll;
const ll INF=1ll<<60;
ll x;
int main()
{
	std::cin>>x;
	ll tmp=sqrt(x)+1;
	if(tmp>x)std::cout<<-1;
	else std::cout<<tmp<<" "<<tmp;
	return 0;
}