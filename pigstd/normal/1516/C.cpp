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

const int M=110;
int a[M],n,sum;
bool dp[M][100010];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();int d=a[1];
	for (int i=2;i<=n;i++)d=__gcd(d,a[i]);
	for (int i=1;i<=n;i++)a[i]/=d;
	for (int i=1;i<=n;i++)sum+=a[i];
	if (sum&1)return puts("0"),0;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=a[i];j<=sum/2;j++)
			dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];
	if (!dp[n][sum/2])return puts("0"),0;
	puts("1");
	for (int i=1;i<=n;i++)
		if (a[i]&1)return printf("%lld\n",i),0;
	
	return 0;
}