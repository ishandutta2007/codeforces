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

const int M=1e5+10;
int dp[M][5],n,a[M];
char s[M];
string ss=" hard";

signed main()
{
	n=read();cin>>s+1;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=4;j++)
			dp[i][j]=dp[i-1][j];
		for (int j=1;j<=4;j++)
			if (s[i]==ss[j])
				dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]),
				dp[i][j-1]+=a[i];
	}cout<<min(dp[n][0],min(dp[n][1],min(dp[n][2],dp[n][3])));
	return 0;
}