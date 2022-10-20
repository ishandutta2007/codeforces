#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1e3;
const int mod=1e9+7;

int a,b,n,k,dp[2][N],p=0,l,r,now,lim;

int main()
{
	memset(dp,0,sizeof(dp));
	scanf("%d%d%d%d",&a,&b,&k,&n);
	n*=2;
	now=a-b;
	l=now-n*k;
	r=now+n*k;
	lim=abs(l);
	if (now+n*k<=0)
	{
		putchar('0');
		return 0;
	}
	for (int i=now;i<=r+k;i++) dp[0][lim+i]=1;
	for (int i=1;i<=n;i++)
	{
		p^=1;
		for (int j=l;j<=r;j++) dp[p][lim+j]=(dp[p^1][min(lim+j+k,lim+r)]-(lim+j-k-1>=0?dp[p^1][lim+j-k-1]:0)+mod)%mod;
		for (int j=l+1;j<=r+k;j++) (dp[p][lim+j]+=dp[p][lim+j-1])%=mod;
	}
	printf("%d",(dp[p][lim+r]-dp[p][lim]+mod)%mod);

	return 0;
}