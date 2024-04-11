#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll n,sum;
int main(){
	ll t,i,a,mx;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		sum=0;
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a);
			sum+=a;
			mx=max(mx,a);
		}
		if(sum<=mx*(n-1))
		{
			printf("%lld\n",mx*(n-1)-sum);
		}
		else
		{
			printf("%lld\n",(n-1-(sum%(n-1)))%(n-1));
		}
	}
	return 0;
}