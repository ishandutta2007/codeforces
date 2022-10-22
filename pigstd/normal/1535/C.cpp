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

const int M=2e5+10;
int n,a[M],dp[M][2];
string s;

signed main()
{
	WT
	{
		cin>>s;n=s.size();int ans=0;
		for (int i=1;i<=n;i++)
			if (s[i-1]=='1')a[i]=1;
			else if (s[i-1]=='0')a[i]=2;
			else a[i]=3;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==2)
			{
				dp[i][0]=dp[i-1][1]+1;
				dp[i][1]=0;ans+=dp[i][0];
			}
			if (a[i]==1)
			{
				dp[i][1]=dp[i-1][0]+1;
				dp[i][0]=0;ans+=dp[i][1];
			}
			if (a[i]==3)
			{
				dp[i][0]=dp[i-1][1]+1;
				dp[i][1]=dp[i-1][0]+1;
				ans+=max(dp[i][0],dp[i][1]);
			}
		}cout<<ans<<endl;
	}
	return 0;
}