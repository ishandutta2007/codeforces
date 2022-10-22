#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
void solve()
{
	ll a,b,k,res=0;
	std::cin>>a>>b>>k;
	res=(k/2)*(a-b);
	if(k&1)res+=a;
	std::cout<<res<<std::endl;
}
int main()
{
	ll t;
	std::cin>>t;
	while(t--)solve();
	return 0;
}