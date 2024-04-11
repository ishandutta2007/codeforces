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
#define N 200010
using namespace std;
ll n,a[N],k;
int main(){
	ll T,i,mx;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		mx=-LINF;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			mx=max(mx,a[i]);
		}
		for(i=0;i<n;i++)
		{
			a[i]=mx-a[i];
		}
		if(k%2==1)
		{
			for(i=0;i<n;i++)
			{
				printf("%lld ",a[i]);
			}
			puts("");
		}
		else
		{
			mx=-LINF;
			for(i=0;i<n;i++)
			{
				mx=max(mx,a[i]);
			}
			for(i=0;i<n;i++)
			{
				printf("%lld ",mx-a[i]);
			}
			puts("");
		}
	}
	return 0;
}