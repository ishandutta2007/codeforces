//AFO countdown:6 Days
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

const int M=5010;
int n,a[M],dp[M],f[M][M];
string s;

signed main()
{
	WT
	{
		n=read();cin>>s;
		for (int i=1;i<=n;i++)
			a[i]=s[i-1]-'a'+1;
		for (int i=n;i>=1;i--)
			for (int j=n;j>=i;j--)
				f[i][j]=a[i]==a[j]?f[i+1][j+1]+1:0;
		for (int i=1;i<=n;i++)
		{
			dp[i]=n-i+1;
			for (int j=1;j<i;j++)
				if (a[f[j][i]+j]<a[f[j][i]+i])
					dp[i]=max(dp[i],dp[j]+n-i-f[j][i]+1);
		}int ans=0;
		for (int i=1;i<=n;i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
		for (int i=n;i>=1;i--)
			for (int j=n;j>=i;j--)
				f[i][j]=0;
	}
	return 0;
}