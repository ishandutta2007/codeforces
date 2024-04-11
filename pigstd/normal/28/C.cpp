#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=55;
double dp[M][M][M],C[M][M];
int n,m,a[M];

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
		a[i]=read();
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];//,cout<<C[i][j]<<' ';puts("");
	}
	dp[0][0][0]=1;
	for (int i=0;i<m;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=n;k++)
				for (int x=0;j+x<=n;x++)
					dp[i+1][j+x][max(k,x/a[i+1]+(x%a[i+1]==0?0:1))]+=dp[i][j][k]*1.0*C[n-j][x];
	double sum=pow(m,n),ans=0;
	for (int i=0;i<=n;i++)
		ans+=dp[m][n][i]*i;
	ans/=sum;printf("%.20lf",ans);
	return 0;
}