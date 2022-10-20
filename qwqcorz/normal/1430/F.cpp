#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int can[N][N],w[N][N];
int dp[N],l[N],r[N],a[N];

signed main()
{
	int n=read(),k=read(),sum=0;
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read(),sum+=a[i]=read();
	for (int i=1;i<=n;i++)
	for (int j=i,sum=k;j<=n;j++)
	{
		if ((r[j]-l[j])*k+sum<a[j]) break;
		if (sum>=a[j])
		{
			sum-=a[j];
			if (l[j]<r[j]) can[i][j]=1,sum=sum?sum:k;
			else can[i][j]=2,sum=sum?sum:(r[j]<l[j+1]?k:0);
		}
		else
		{
			can[i][j]=l[j]<r[j]&&(r[j]-l[j]-1)*k+sum>=a[j]?1:2;
			sum=(k-(a[j]-sum)%k)%k;
			if (!sum) sum=can[i][j]==1||r[j]<l[j+1]?k:0;
		}
		w[i][j]=sum%k;
	}
//	for (int i=1;i<=n;i++)
//	for (int j=i;j<=n;j++) print(i,','),print(j,':'),print(can[i][j],' '),print(w[i][j]);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<i;j++)
	if (can[j+1][i])
	if (can[j+1][i]==1||r[i]<l[i+1])
	dp[i]=min(dp[i],dp[j]+w[j+1][i]);
	int ans=dp[N-1];
	for (int i=0;i<n;i++) if (can[i+1][n]) ans=min(ans,dp[i]);
	print(ans<dp[N-1]?sum+ans:-1);
	
	return 0;
}