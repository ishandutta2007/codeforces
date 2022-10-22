#include<bits/stdc++.h>
#define int long long
#define pb push_back
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

const int inf=1e9;
const int M=82;
const int N=M*M/2;
int dp[M][N][M],n,a[M],cnt,t[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (a[i])t[++cnt]=i;
	}
	if (cnt==0)
	{
		for (int i=0;i<=n*(n-1)/2;i++)
			cout<<0<<' ';
		return 0;
	}
	for (int i=0;i<M;i++)
		for (int j=0;j<N;j++)
			for (int k=0;k<M;k++)dp[i][j][k]=inf;
	for (int i=1;i<=n;i++)
	{
		dp[i][abs(i-t[1])][1]=(i-1)*(i-2)/2;
		for (int j=0;j<=n*(n-1)/2;j++)
			for (int k=1;k<=i&&k<cnt;k++)
			{
				if (dp[i][j][k]==inf)continue;
				int res=cnt-k;
				for (int l=i+1;l<=n-res+1;l++)
				{
					if (j+abs(l-t[k+1])<=n*(n-1)/2)
						dp[l][j+abs(l-t[k+1])][k+1]=min(dp[l][j+abs(l-t[k+1])][k+1],
						dp[i][j][k]+(l-i-2)*(l-i-1)/2);
				}
			}
	}
	int minn=(n-cnt+1)*(n-cnt)/2;
	for (int i=0;i<=n*(n-1)/2;i++)
	{
		for (int j=cnt;j<=n;j++)
			minn=min(minn,dp[j][i][cnt]+(n-j)*(n-j-1)/2);
//		cout<<minn<<' ';
		cout<<(n-cnt-1)*(n-cnt)/2-minn<<' ';
	}
	return 0;
}