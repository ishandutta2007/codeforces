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
ll n;
int main(){
	ll t,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
		{
			if(i*(i+1)/2==n+1)
			{
				printf("%lld\n",i+1);
				break;
			}
			else if(i*(i+1)/2>=n)
			{
				printf("%lld\n",i);
				break;
			}
		}
	}
	return 0;
}