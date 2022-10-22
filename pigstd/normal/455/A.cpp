#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int n,a[M],dp[M],t[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
	for (int i=1;i<=1e5;i++)
		dp[i]=max(dp[i-1],dp[i-2]+t[i]*i);
	cout<<dp[(int)(1e5)];
	return 0;
}