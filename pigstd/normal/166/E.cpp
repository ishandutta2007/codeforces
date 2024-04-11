#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Mod=1e9+7;
const int M=1e7+10;
int dp[2][4],n;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),dp[0][0]=1;
	for (int i=1;i<=n;i++)
		dp[i&1][0]=(dp[(i-1)&1][1]+dp[(i-1)&1][2]+dp[(i-1)&1][3])%Mod,
		dp[i&1][1]=(dp[(i-1)&1][0]+dp[(i-1)&1][2]+dp[(i-1)&1][3])%Mod,
		dp[i&1][2]=(dp[(i-1)&1][0]+dp[(i-1)&1][1]+dp[(i-1)&1][3])%Mod,
		dp[i&1][3]=(dp[(i-1)&1][0]+dp[(i-1)&1][1]+dp[(i-1)&1][2])%Mod;
	cout<<dp[n&1][0];
	return 0;
}