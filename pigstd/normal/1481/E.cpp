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
const int M=5e5+10;
int n,a[M],dp[M],l[M],r[M],p[M],pp[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)r[a[i]]=i;
	for (int i=n;i>=1;i--)l[a[i]]=i;
	for (int i=n;i>=1;i--)
		p[i]=p[pp[a[i]]]+1,pp[a[i]]=i;
	for (int i=n;i>=1;i--)
		if (i==l[a[i]])dp[i]=max(dp[i+1],dp[i]+p[i]+dp[r[a[i]]+1]);
		else dp[i]=max(dp[i+1],p[i]);
	cout<<n-dp[1];
	return 0;
}