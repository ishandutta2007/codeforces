#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,tmp=0,pre=0;
ll a[1000001];
void start()
{
	std::cin>>n>>k;
	for(ll i=1;i<=n;++i)std::cin>>a[i];
}
void work()
{
	while(a[pre]-tmp<=0&&pre<=n)++pre;
	if(pre>n)std::cout<<0<<std::endl;
	else std::cout<<a[pre]-tmp<<std::endl,tmp=a[pre];
}
int main()
{
	start();
	std::sort(a+1,a+n+1);
	for(ll i=1;i<=k;++i)work();
	return 0;
}