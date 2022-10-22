#include<bits/stdc++.h>
//#define int long long
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

const int inf=1e9;
const int M=25;
const int N=(1<<20)+10;
const int P=4e5;
int dp[N][2],n,sz[N],sum[M],t[M][P*2+10],minn[M];
string s;

signed main()
{
	n=read();;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		for (int j=0;j<s.size();j++)
		{
			sum[i]+=s[j]=='('?1:-1,minn[i]=min(minn[i],sum[i]);
			if (sum[i]<=minn[i])t[i][sum[i]+P]++;
		}
	}
	for (int i=1;i<(1<<n);i++)
		for (int j=1;j<=n;j++)
			if (i&(1<<(j-1)))sz[i]+=sum[j];
	for (int i=1;i<(1<<n);i++)
		dp[i][0]=dp[i][1]=-inf;
	int ans=0;
	for (int i=0;i<(1<<n);i++)
		for (int j=1;j<=n;j++)
			if (!(i&(1<<(j-1))))
			{
				int x=i|(1<<(j-1));
				if (sz[i]+minn[j]>=0)
					dp[x][1]=max(dp[x][1],dp[i][1]+t[j][P-sz[i]]);
				else dp[x][0]=max(dp[x][0],dp[i][1]+t[j][P-sz[i]]);
			}
	for (int i=0;i<(1<<n);i++)
		ans=max(ans,max(dp[i][0],dp[i][1]));
	cout<<ans<<endl;
	return 0;
}