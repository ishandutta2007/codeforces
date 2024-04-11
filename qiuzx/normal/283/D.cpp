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
#define N 5010
using namespace std;
ll n,a[N],odd[N],pw2[N],dp[N],ans;
int main(){
	ll i,j;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		odd[i]=a[i];
		while(odd[i]%2==0)
		{
			pw2[i]++;
			odd[i]/=2;
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(odd[j]%odd[i]==0)
			{
				if(pw2[i]<(i-j))
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
				else
				{
					if(pw2[j]==pw2[i]-(i-j))
					{
						dp[i]=max(dp[i],dp[j]+1);
					}
				}
			}
		}
	}
	ans=n;
	for(i=0;i<n;i++)
	{
		ans=min(ans,n-dp[i]-1);
	}
	printf("%I64d\n",ans);
	return 0;
}