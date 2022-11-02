#include<bits/stdc++.h>
using namespace std;
long long a[100200],mod,sum[100010];
int main()
{
	register int n,i;
	long long ans=0;
	scanf("%d %I64d",&n,&mod);
	for (i=1;i<=n;i++) scanf("%I64d",&a[i]),sum[i]=sum[i-1]+a[i];
	for (i=1;i<=n;i++) ans=max(ans,sum[i]%mod+(sum[n]-sum[i])%mod);
	printf("%I64d",ans);
}