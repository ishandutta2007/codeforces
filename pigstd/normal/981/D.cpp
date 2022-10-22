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

const int M=55;
int n,k,a[M],dp[M][M],sum[M],ans;

bool check(int x)
{
	memset(dp,0,sizeof(dp));dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			for (int p=0;p<i;p++)
				dp[i][j]|=dp[p][j-1]&(((sum[i]-sum[p])&x)==x);
	return dp[n][k];
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),sum[i]=sum[i-1]+a[i];
	for (int i=60;i>=0;i--)
		if (check(ans|(1ll<<i)))ans|=(1ll<<i);
	cout<<ans<<endl;
	return 0;
}