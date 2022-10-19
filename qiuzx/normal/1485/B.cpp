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
ll n,q,k,a[N];
int main(){
	ll i,l,r;
	scanf("%lld%lld%lld",&n,&q,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		l--;
		r--;
		printf("%lld\n",2*l-2*r+a[r]-a[l]+k-1);
	}
	return 0;
}