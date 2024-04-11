#include <bits/stdc++.h>
using namespace std;
int cnt[1000007],dp[10][10],dpl[10][10];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {int t; scanf("%d",&t); cnt[t]++;}
	for(int i=3;i<=m+2;i++)
	{
		for(int j=0;j<=2;j++) for(int k=j;k<=j+2;k++)
		{
			int t=0;
			for(int z=k-j;z<=k-j+2;z++) if(z+j<=cnt[i-2]) t=max(dpl[k-j][z]+(cnt[i-2]-z-j)/3+j,t);
			dp[j][k]=t;
		}
		for(int j=0;j<=2;j++) for(int k=j;k<=j+2;k++) dpl[j][k]=dp[j][k];
	}
	printf("%d",dp[0][0]);
}