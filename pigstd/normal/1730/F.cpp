#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=5010;
const int N=1<<8;
int dp[M][10][N],n,k,a[M],t[M],s[M];

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]=i;
	for (int i=1;i<=n;i++)for (int j=1;j<i;j++)if (t[j]>t[i])s[i]++;
//	for (int i=1;i<=n;i++)cerr<<t[i]<<(i==n?'\n':' ');
//	for (int i=1;i<=n;i++)cerr<<s[i]<<(i==n?'\n':' ');
	for (int i=0;i<=n;i++)for (int j=0;j<=k;j++)for (int w=0;w<(1<<k);w++)dp[i][j][w]=inf;
	dp[0][0][0]=0;
	for (int i=0;i<n;i++)for (int j=0;j<=k;j++)for (int w=0;w<(1<<k);w++)
	{
		int v=dp[i][j][w];if (v==inf)continue;
		int num=i+1-j;
//		cerr<<i<<' '<<j<<' '<<w<<' '<<v<<' '<<num<<'\n';
		for (int w1=0;w1<k&&w1+num+1<=n;w1++)
			if ((w>>w1)&1^1)
			{
				int val=v+s[w1+num+1];val-=(t[num]>t[num+1+w1]);
				for (int w2=0;w2<w1;w2++)
					if ((w>>w2)&1^1)val-=(t[num+1+w2]>t[num+1+w1]);
				for (int w2=w1+1;w2<k;w2++)
					if ((w>>w2)&1)val+=(t[num+1+w2]>t[num+1+w1]);
//				if (val<0)cerr<<"warning:"<<w1<<'\n';
//				assert(val>=0);
				ckmin(dp[i+1][j+1][w^(1<<w1)],val);
			}
		int val=v+s[num],S=w,S2=j;
		for (int w2=0;w2<k;w2++)
			if ((w>>w2)&1)val+=(t[num+1+w2]>t[num]);
		while(S&1)S>>=1,S2--;
		S>>=1;ckmin(dp[i+1][S2][S],val);
	}
	cout<<dp[n][0][0]<<'\n';
	return 0;
}