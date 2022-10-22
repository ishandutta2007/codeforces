#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=110;
const int N=1010;
int a[M],n,m;
double dp[M][N*M],sum[M][N*M],ans;

signed main()
{
	n=read(),m=read();int Sum=0;
	for (int i=1;i<=n;i++)a[i]=read(),Sum+=a[i];
	for (int i=1;i<=m;i++)
		if (i!=a[1])dp[1][i]=1;
	for (int i=1;i<=n*m;i++)
		sum[1][i]=sum[1][i-1]+dp[1][i];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=n*m;j++)
		{
			dp[i][j]=sum[i-1][j-1]-(j<=m?0:sum[i-1][j-m-1]);
			if (j-a[i]>=0)dp[i][j]-=dp[i-1][j-a[i]];
			dp[i][j]/=m-1;
//			for (int k=1;k<=m&&k<=j;k++)
//				if (k!=a[i])
//					dp[i][j]+=dp[i-1][j-k]*1.0/(m-1);
			sum[i][j]=sum[i][j-1]+dp[i][j];
		}
	for (int i=n;i<Sum;i++)ans+=dp[n][i];ans++;
	printf("%.12lf",ans);
	return 0;
}