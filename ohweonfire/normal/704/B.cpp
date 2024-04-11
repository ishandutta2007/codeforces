#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=5111;
const int inf=0x3f3f3f3f;

int n,s,e,x[maxn],a[maxn],b[maxn],c[maxn],d[maxn];

LL dp[maxn][maxn];
inline void upd(LL&x,LL y){if(x>y)x=y;}
int main()
{
	scanf("%d%d%d",&n,&s,&e);
	for(int i=1;i<=n;i++)scanf("%d",x+i);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=n;i++)scanf("%d",d+i);
	
	for(int i=1;i<=n;i++)a[i]+=x[i];
	for(int i=1;i<=n;i++)b[i]-=x[i];
	for(int i=1;i<=n;i++)c[i]+=x[i];
	for(int i=1;i<=n;i++)d[i]-=x[i];
	
	memset(dp,0x40,sizeof(dp));
	if(s==1)dp[2][1]=d[1];
	else if(e==1)dp[2][1]=b[1];
	else dp[2][1]=b[1]+d[1];
	for(int i=2;i<=n;i++)for(int j=1;j<=i;j++)
	{
		if(s==i)
		{
			upd(dp[i+1][j+1],dp[i][j]+d[i]);
			if(j==1&&i>e&&i<n);else upd(dp[i+1][j],dp[i][j]+c[i]);
		}
		else if(e==i)
		{
			upd(dp[i+1][j+1],dp[i][j]+b[i]);
			if(j==1&&i>s&&i<n);else upd(dp[i+1][j],dp[i][j]+a[i]);
		}
		else
		{
			upd(dp[i+1][j+1],dp[i][j]+d[i]+b[i]);
			if(j==1&&i>e);else upd(dp[i+1][j],dp[i][j]+d[i]+a[i]);
			if(j==1&&i>s);else upd(dp[i+1][j],dp[i][j]+c[i]+b[i]);
			if(j<=2&&i>s&&i>e&&i<n);else upd(dp[i+1][j-1],dp[i][j]+c[i]+a[i]);
		}
	}
	printf("%lld\n",dp[n+1][1]);
	return 0;
}