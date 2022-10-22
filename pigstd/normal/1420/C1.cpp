#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,a[M],dp[M][2];

signed main()
{
	WT
	{
		n=read();read();
		for (int i=1;i<=n;i++)a[i]=read();
//		dp[0][0]=-1e18;
		for (int i=1;i<=n;i++)
			dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]),
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]-a[i]);
		cout<<max(dp[n][0],dp[n][1])<<endl;
	}
	return 0;
}