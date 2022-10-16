#include <iostream>
#include <algorithm>

using namespace std;

long long a[100069],dp[100069];

int main()
{
	long long n,i,k;
	
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&k);
		a[k]+=k;
	}
	for(i=1;i<=100000;i++)
	{
		if(i==1)
		{
			k=0;
		}
		else
		{
			k=dp[i-2];
		}
		dp[i]=max(dp[i-1],k+a[i]);
	}
	printf("%I64d\n",dp[100000]);
}