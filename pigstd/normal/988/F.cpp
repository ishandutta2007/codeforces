#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=2010;
int a,n,m,t[M],x[M],l[M],dp[M][M];
vector<int>v[M];

signed main()
{
	a=read(),n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int l=read(),r=read();
		for (int j=l+1;j<=r;j++)
			t[j]++;
	}
	for (int i=1;i<=m;i++)
	{
		x[i]=read();l[i]=read();
		v[x[i]].pb(i);
	}
	for (int j=1;j<=m;j++)dp[0][j]=inf;
	for (int j=0;j<v[0].size();j++)
		dp[0][v[0][j]]=0;
	for (int i=1;i<=a;i++)
	{
		for (int j=1;j<=m;j++)dp[i][j]=min(inf,dp[i-1][j]+l[j]);
		int minn=inf;
		for (int j=1;j<=m;j++)
			minn=min(minn,dp[i-1][j]+l[j]);
		if (t[i]==0)
		{
			for (int j=0;j<=m;j++)
				minn=min(minn,dp[i-1][j]);
			dp[i][0]=minn;
		}
		else dp[i][0]=inf;
		for (int j=0;j<v[i].size();j++)
			dp[i][v[i][j]]=min(dp[i][v[i][j]],minn);
	}
//	for (int i=0;i<=a;i++)
//		for (int j=0;j<=m;j++)
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	int minn=inf;
	for (int i=0;i<=m;i++)
		minn=min(minn,dp[a][i]);
	if (minn==inf)puts("-1");
	else cout<<minn<<endl;
	return 0;
}