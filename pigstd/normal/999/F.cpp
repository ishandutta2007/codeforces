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

const int M=1e5+10;
const int N=5010;
int n,k,dp[N][N],ans;
int c[M],f[M],h[M],t[M],t2[M];

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n*k;i++)
		t[c[i]=read()]++;
	for (int i=1;i<=n;i++)
		f[i]=read(),t2[f[i]]++;
	for (int i=1;i<=k;i++)
		h[i]=read();
	for (int tt=1;tt<=1e5;tt++)
	{
		if (t[tt]==0)continue;
		int x=t[tt],s=t2[tt];
		if (s==0)continue;
//		cout<<x<<' '<<s<<' ';
		//s ren x shu
//		memset(dp,0,sizeof(dp));
		for (int i=1;i<=x;i++)
			for (int j=1;j<=s;j++)
				for (int p=0;p<=min(i,k);p++)
					dp[i][j]=max(dp[i][j],h[p]+dp[i-p][j-1]);
		ans+=dp[x][s];//cout<<dp[x][s]<<endl;
		for (int i=1;i<=x;i++)
			for (int j=1;j<=s;j++)dp[i][j]=0;
	}
	cout<<ans;
	return 0;
}