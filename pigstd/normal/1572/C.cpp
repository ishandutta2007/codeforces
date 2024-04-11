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

const int inf=1e18;
const int M=3010;
int n,dp[M][M],a[M];
vector<int>v[M];

signed main()
{
	WT
	{
		n=read();
		a[1]=a[n+2]=n+1;
		for (int i=2;i<=n+1;i++)
			a[i]=read();n+=2;
		for (int i=1;i<=n;i++)v[i].clear(); 
		for (int i=1;i<=n;i++)
			v[a[i]].pb(i);
		for (int i=n;i>=1;i--)
		{
			for (int j=i+1;j<=n;j++)
			{
				int minn=inf;
				for (int k=0;k<v[a[j]].size();k++)
				{
					int u=v[a[j]][k];
					if (u>j)break;
					if (u>i)
						minn=min(minn,dp[u][j]+dp[i][u-1]+(a[j]!=a[i]));
				}
				dp[i][j]=minn;
			}
		}
		cout<<dp[1][n]-1<<endl;
	}
	return 0;
}