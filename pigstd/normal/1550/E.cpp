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
const int M=2e5+10;
const int N=20;
int dp[M],n,k,a[M],f1[20][M],f2[20][M];
string s;

bool check(int x)
{
	for (int i=1;i<=k;i++)f1[i][n+1]=inf;
	for (int i=1;i<=k;i++)
		for (int j=n;j>=1;j--)
		{
			f1[i][j]=f1[i][j+1];
			if (a[j]==i||a[j]==-1)f2[i][j]=f2[i][j+1]+1;
			else f2[i][j]=0;
			if (f2[i][j]>=x)f1[i][j]=j+x-1;
		}
	for (int i=1;i<(1<<k);i++)
	{
		dp[i]=inf;
		for (int j=1;j<=k;j++)
		{
			if (!(i&(1<<(j-1))))continue;
			if (dp[i^(1<<(j-1))]!=inf)
				dp[i]=min(dp[i],f1[j][dp[i^(1<<(j-1))]+1]);
		}
	}
	return dp[(1<<k)-1]!=inf;
}

signed main()
{
	cin>>n>>k>>s;
	for (int i=0;i<n;i++)
		a[i+1]=s[i]=='?'?-1:s[i]-'a'+1;
	int tl=1,tr=n,p=0;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))p=Mid,tl=Mid+1;
		else tr=Mid-1;
	}cout<<p<<endl;
//	for (int i=1;i<=n;i++)cout<<check(i)<<endl;
	return 0;
}