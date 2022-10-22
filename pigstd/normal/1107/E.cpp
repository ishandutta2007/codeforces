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

const int M=110;
int n,a[M],b[M],dp[M][M][M];
string s;

signed main()
{
	n=read();cin>>s;
	for (int i=1;i<=n;i++)
		b[i]=s[i-1]-'0';
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			a[i]=max(a[i],a[i-j]+a[j]);
	for (int len=1;len<=n;len++)
		for (int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for (int k=0;k<=n;k++)
			{
				dp[i][j][k]=dp[i+1][j][0]+a[k+1];
				for (int p=i+1;p<=j;p++)
					if (b[p]==b[i])
						dp[i][j][k]=max(dp[i][j][k],dp[i+1][p-1][0]+dp[p][j][k+1]);
			}
		}
	cout<<dp[1][n][0]<<endl;
	return 0;
}