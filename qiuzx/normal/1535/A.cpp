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
ll T,a[5];
int main(){
	ll i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3]);
		ll x=max(a[0],a[1]);
		ll y=max(a[2],a[3]);
		sort(a,a+4);
		if(max(x,y)==a[3]&&min(x,y)==a[2])
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}