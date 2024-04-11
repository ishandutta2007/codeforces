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
vector<ll> a;
int main(){
	ll T,i,x;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		a.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		for(i=0;i<n;i++)
		{
			if(a[i]!=a[0])
			{
				break;
			}
		}
		printf("%lld\n",n-i);
	}
	return 0;
}