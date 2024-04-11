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
ll n,k;
int main(){
	ll T,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		if(n%2==0)
		{
			printf("%lld\n",(k-1)%n+1);
		}
		else
		{
			x=k/(n/2);
			y=k%(n/2);
			x*=(n/2+1);
			if(y==0)
			{
				x--;
			}
			printf("%lld\n",(x+y-1)%n+1);
		}
	}
	return 0;
}