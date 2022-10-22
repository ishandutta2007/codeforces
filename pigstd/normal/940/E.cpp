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

const int inf=1e18;
const int M=1e5+10;
int n,c,a[M],sum,dp[M],f[M][20];

int query(int a,int b)
{
	int k=log2((double)(b-a+1));
	return min(f[a][k],f[b-(1<<k)+1][k]);
}

void RMQ()
{
	for (int i=1;(1<<i)<=n;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
			f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
}

signed main()
{
	n=read(),c=read();memset(f,0x3f,sizeof(f));
	for (int i=1;i<=n;i++)f[i][0]=a[i]=read(),sum+=a[i];
	RMQ();
	for (int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if (i>=c)dp[i]=max(dp[i],dp[i-c]+query(i-c+1,i));
	}
	cout<<sum-dp[n]<<endl;
	return 0;
}
//1 1 2 3 3 5 7 8 9 11
//0 0 1 1 1 3 5 6 7 9
//fyy->zmf->pigstd->L->cmll->dX->zzc