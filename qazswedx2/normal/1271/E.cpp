#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,lim=4;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	while(m>=lim-1) lim<<=1;
	ll nw=lim/4,nw2=m-lim/2+1;
	//printf("n=%lld,m=%lld,lim=%lld,nw=%lld,nw2=%lld\n",n,m,lim,nw,nw2);
	ll ans1=(n-nw2)/nw,ans2;
	ans1-=(ans1%2);
	lim=1;
	while(m>=lim) lim<<=1;
	ll nw3=lim/2,nw4=m-lim/2;
	ans2=(n-nw4)/nw3;
	ans2-=(ans2-1)%2;
	printf("%I64d",max(ans1,ans2));
	return 0;
}