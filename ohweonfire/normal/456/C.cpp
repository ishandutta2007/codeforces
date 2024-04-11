#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[100005],a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	dp[1]=a[1];
	for(int i=2;i<=100000;i++)
		dp[i]=max(dp[i-1],dp[i-2]+i*a[i]);
	printf("%I64d\n",dp[100000]);
	return 0;
}