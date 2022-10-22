#include<iostream>
#include<cstdio>
#include<string>
typedef long long ll;
const ll INF=1ll<<60;
ll n;
char c[10001];
int main()
{
	std::cin>>n;
	getchar();
	for(ll i=1;i<=n;++i)c[i]=getchar();
	for(ll i=1,w=1;i<=n&&w<=n;++i,w+=i)std::cout<<c[w];
	return 0;
}