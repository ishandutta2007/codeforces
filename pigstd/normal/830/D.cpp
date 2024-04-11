//AFO countdown:???
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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
const int M=410;
int n,dp[M][M];

signed main()
{
	n=read();dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
			for (int k=0;j+k-1<=n;k++)
				dp[i][j+k+1]=(dp[i][j+k+1]+dp[i-1][j]*dp[i-1][k])%Mod,
				dp[i][j+k]=(dp[i][j+k]+dp[i-1][j]*dp[i-1][k]%Mod*(2*(j+k)+1))%Mod,
				dp[i][j+k-1]=(dp[i][j+k-1]+dp[i-1][j]*dp[i-1][k]%Mod*(j+k)*(j+k-1))%Mod;
	}cout<<dp[n][1]<<' ';
	return 0;
}