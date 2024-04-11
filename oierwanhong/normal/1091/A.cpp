#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
ll a,b,c;
int main()
{
	std::cin>>a>>b>>c;
	--b;--c;--c;
	ll ans=a;
	if(ans>b)ans=b;
	if(ans>c)ans=c;
	std::cout<<(ans*3+3);
	return 0;
}