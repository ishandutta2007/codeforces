#include<bits/stdc++.h>
#define int long long
#define pb push_back
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

const int Mod=998244353;
const int M=1010;
int n,m,ans,dp[M][M][2][4],a1[M],a2[M];
char s1[M],s2[M];

void add(int &x,int y){x=(x+y)%Mod;}

signed main()
{
	cin>>s1+1>>s2+1;
	n=strlen(s1+1),m=strlen(s2+1);
	for (int i=1;i<=n;i++)a1[i]=s1[i]-'a'+1;
	for (int i=1;i<=m;i++)a2[i]=s2[i]-'a'+1;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
		{
			if (i<n)add(dp[i+1][j][0][1],1);
			if (j<m)add(dp[i][j+1][1][2],1);
			for (int k=0;k<4;k++)
			{
				if (a1[i]!=a1[i+1]&&i<n)add(dp[i+1][j][0][k|1],dp[i][j][0][k]);
				if (a1[i]!=a2[j+1]&&j<m)add(dp[i][j+1][1][k|2],dp[i][j][0][k]);
				if (a2[j]!=a1[i+1]&&i<n)add(dp[i+1][j][0][k|1],dp[i][j][1][k]);
				if (a2[j]!=a2[j+1]&&j<m)add(dp[i][j+1][1][k|2],dp[i][j][1][k]);
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			add(ans,dp[i][j][0][3]),add(ans,dp[i][j][1][3]);
	cout<<ans<<endl;
	return 0;
}