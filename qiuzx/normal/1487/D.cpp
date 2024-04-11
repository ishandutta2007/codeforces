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
ll n,l,r;
int main(){
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		l=3;
		r=sqrt(2*n-1);
		if(r%2==0)
		{
			r--;
		}
		printf("%lld\n",max((ll)0,(r-l)/2+1));
	}
	return 0;
}