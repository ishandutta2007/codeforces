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

const int M=4010;
int n,p[M],cnt,a[M],b[M],dp[M];

signed main()
{
	WT
	{
		n=read();cnt=0;
		for (int i=1;i<=2*n;i++)p[i]=read();
		for (int i=1;i<=2*n;i++)
		{
			int pp=i;
			for (int j=i+1;j<=2*n;j++)
				if (p[j]<p[i])pp=j;
				else break;
			i=pp;a[++cnt]=pp;
		}
		for (int i=1;i<=cnt;i++)b[i]=a[i]-a[i-1];
		for (int i=1;i<=n;i++)dp[i]=0;
		dp[0]=1;
		for (int i=1;i<=cnt;i++)
			for (int j=n;j>=b[i];j--)
				dp[j]|=dp[j-b[i]];
		if (dp[n])YES
		else NO
	}
}