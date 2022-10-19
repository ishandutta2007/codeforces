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
ll n;
int main(){
	ll T,x;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n%2==1)
		{
			puts("NO");
			continue;
		}
		n/=2;
		x=sqrt(n);
		if(x*x==n)
		{
			puts("YES");
			continue;
		}
		x=sqrt(n/2);
		if(x*x*2==n)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}