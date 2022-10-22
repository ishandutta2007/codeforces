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

const int inf=1e18;
const int M=5010;
int n,cnt1,cnt2,dp[M][M],a[M];
vector<int>v;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),cnt1+=a[i],cnt2+=a[i]^1;
		if (a[i])v.pb(i);
	}
	for (int i=1;i<=n;i++)dp[i][0]=inf; 
	for (int i=1;i<=cnt1;i++)
		for (int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if (a[j]==0)
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(j-v[i-1]));//,cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;;
		}cout<<dp[cnt1][n];
	return 0;
}