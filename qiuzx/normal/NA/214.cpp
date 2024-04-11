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
ll n,a[N];
int main(){
	ll T,i;
	bool hv;
	scanf("%lld",&T);
	while(T--)
	{
		hv=true;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(i>0&&a[i]!=a[i-1])
			{
				hv=false;
			}
		}
		if(hv)
		{
			printf("%lld\n",n);
		}
		else
		{
			puts("1");
		}
	}
	return 0;
}