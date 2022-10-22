#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=5010;
int dp[M][M],n,a[M],b[M],sum;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read(),sum+=a[i]*b[i];
	for (int i=1;i<=n;i++)dp[i][i]=dp[i+1][i]=dp[i][i-1]=sum;
	for (int len=2;len<=n;len++)
		for (int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			dp[i][j]=dp[i+1][j-1]-a[i]*b[i]-a[j]*b[j]+a[i]*b[j]+a[j]*b[i];
		}int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)ans=max(ans,dp[i][j]);
	cout<<ans<<endl;
	return 0;
}