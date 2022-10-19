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
#define N 200010
using namespace std;
ll n,k,v[N];
int main(){
	ll t,i,gcd;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&v[i]);
			if(i!=0)
			{
				v[i]-=v[0];
			}
		}
		k-=v[0];
		gcd=v[1];
		for(i=2;i<n;i++)
		{
			gcd=__gcd(gcd,v[i]);
		}
		//cout<<k<<" "<<gcd<<endl;
		if(k%gcd==0)
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