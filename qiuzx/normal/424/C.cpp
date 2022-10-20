#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define ll long long
#define F first
#define S second
#define N 1000010
using namespace std;
ll n,p[N],xor_sum[N],ans=0;
ll calc(ll x)
{
	if(n%x==0)
	{
		return xor_sum[x-1]*((n/x)%2);
	}
	return (xor_sum[x-1]*((n/x)%2))^(xor_sum[n%x]);
}
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&p[i]);
		ans^=p[i];
	}
	xor_sum[0]=0;
	for(i=1;i<=n;i++)
	{
		xor_sum[i]=(xor_sum[i-1]^i);
	}
	for(i=1;i<=n;i++)
	{
	//	cout<<i<<" "<<calc(i)<<endl;
		ans^=calc(i);
	}
	printf("%lld\n",ans);
	return 0;
}