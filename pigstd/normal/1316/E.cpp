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
const int N=(1<<7)+10;
int n,k,p,dp[M][N];

struct node
{
	int a,s[10];
}a[M];

bool cmp(node a,node b)
{
	return a.a>b.a;
}

int cnt(int x)
{
	int res=0;
	for (int i=0;i<=7;i++)
		if (x&(1<<i))res++;
	return res;
}

signed main()
{
	n=read(),p=read(),k=read();
	for (int i=1;i<=n;i++)
		a[i].a=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=p;j++)
			a[i].s[j]=read();
	sort(a+1,a+1+n,cmp);
	for (int j=1;j<(1<<p);j++)
		dp[0][j]=-inf;
	for (int i=1;i<=n;i++)
		for (int j=0;j<(1<<p);j++)
		{
			if (i-cnt(j)<=k)dp[i][j]=dp[i-1][j]+a[i].a;
			else dp[i][j]=dp[i-1][j];
			for (int kk=1;kk<=p;kk++)
				if (j&(1<<(kk-1)))
					dp[i][j]=max(dp[i][j],dp[i-1][j^(1<<(kk-1))]+a[i].s[kk]);
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
	cout<<dp[n][(1<<p)-1];
	return 0;
}