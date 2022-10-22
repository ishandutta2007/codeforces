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

const int M=110;
int dp1[M][M],dp2[M][M],n,m,k;

signed main()
{
	WT
	{
		n=read(),m=read(),k=read();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				if (i==1&&j==1)dp1[i][j]=dp2[i][j]=0;
				else if (i==1)dp1[i][j]=dp1[i][j-1]+i,dp2[i][j]=dp2[i][j-1]+i;
				else if (j==1)dp1[i][j]=dp1[i-1][j]+j,dp2[i][j]=dp2[i-1][j]+j;
				else dp1[i][j]=min(dp1[i-1][j]+j,dp1[i][j-1]+i),
					dp2[i][j]=max(dp2[i-1][j]+j,dp2[i][j-1]+i);
			}
		if (k<=dp2[n][m]&&k>=dp1[n][m])YES
		else NO
	}
	return 0;
}