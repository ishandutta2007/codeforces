#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int T,n,dp[M],a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		dp[1]=a[1],dp[2]=a[1]+a[2];dp[3]=a[3]+a[1],dp[4]=a[4]+a[1];
		for (int i=5;i<=n;i++)dp[i]=min(a[i]+min(dp[i-2],dp[i-3]),a[i]+a[i-1]+min(dp[i-3],dp[i-4]));
		cout<<min(min(dp[n],dp[max(n-1,1)]),dp[max(n-2,1)])<<endl;
	}
}