#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,a[maxn],dp[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<=1000000;i++)dp[i]=a[i];
	for(int i=1;i<=1000000;i++)if(a[i])
		for(int j=i+i;j<=1000000;j+=i)if(a[j])
			dp[j]=max(dp[j],dp[i]+a[j]);
	printf("%d\n",*max_element(dp+1,dp+1000001));
	return 0;
}