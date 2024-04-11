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
ll n;
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				printf("()");
			}
			for(j=i;j<n;j++)
			{
				printf("(");
			}
			for(j=i;j<n;j++)
			{
				printf(")");
			}
			puts("");
		}
	}
	return 0;
}