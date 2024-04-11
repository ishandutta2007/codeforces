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
#define N 100010
using namespace std;
ll a,b,c,m;
int main(){
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&m);
		if(m>a+b+c-3||m<2*max(a,max(b,c))-a-b-c-1)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}