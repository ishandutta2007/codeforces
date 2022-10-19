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
#define N 100010
using namespace std;
ll n,a[N],x;
int main(){
	ll T,i,sum;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&x);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		if(n==1)
		{
			if(a[0]==x)
			{
				puts("NO");
			}
			else
			{
				puts("YES");
				printf("%lld\n",a[0]);
			}
			continue;
		}
		if(sum==x)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		sum=0;
		for(i=0;i<n;i++)
		{
			if(sum+a[i]==x)
			{
				printf("%lld %lld ",a[i+1],a[i]);
				sum+=a[i+1]+a[i];
				i++;
			}
			else
			{
				printf("%lld ",a[i]);
				sum+=a[i];
			}
		}
		puts("");
	}
	return 0;
}