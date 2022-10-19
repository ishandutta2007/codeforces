//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll xsum[N];
int main(){
	ll T,a,b,i;
	xsum[0]=0;
	for(i=1;i<N;i++)
	{
		xsum[i]=(xsum[i-1]^i);
	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		b^=xsum[a-1];
		if(b==0)
		{
			printf("%lld\n",a);
		}
		else if(b!=a)
		{
			printf("%lld\n",a+1);
		}
		else
		{
			printf("%lld\n",a+2);
		}
	}
	return 0;
}