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
#define N 110
using namespace std;
ll n,m,r[N],b[N];
int main(){
	ll t,i,j,s1,s2,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		s1=0;
		s2=0;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&r[i]);
			sum+=r[i];
			s1=max(s1,sum);
		}
		scanf("%lld",&m);
		sum=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
			sum+=b[i];
			s2=max(s2,sum);
		}
		printf("%lld\n",s1+s2);
	}
	return 0;
}