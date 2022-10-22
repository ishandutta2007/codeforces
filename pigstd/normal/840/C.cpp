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

const int Mod=1e9+7;
const int M=310;
int dp[M][M][M],cnt,n,a[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j=2;j*j<=a[i];j++)
			while(a[i]%(j*j)==0)a[i]/=j*j;
	}
	sort(a+1,a+1+n);dp[0][0][0]=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=a[i-1])
		{
			for (int j=0;j<=i;j++)
				for (int k=1;k<=j;k++)
					dp[i-1][j][0]=(dp[i-1][j][0]+dp[i-1][j][k])%Mod,dp[i-1][j][k]=0;
			cnt=0;
		}
		for (int j=0;j<=i;j++)
			for (int k=0;k<=j;k++)
			{
				if (j&&k)dp[i][j][k]=(dp[i][j][k]+(2*cnt-(k-1))*dp[i-1][j-1][k-1])%Mod;
				dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k]*(i-(2*cnt-k)-(j-k))%Mod)%Mod;
				dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+1][k]*(j+1-k))%Mod;
//				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
			}cnt++;
	}cout<<dp[n][0][0]<<endl;
	return 0;
}