//AFO countdown:???
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

const int Mod=1e9+9;
const int M=1e6+10;
int n,dp[M],f[M],res;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

signed main()
{
	n=read()/2;
	dp[1]=2;f[1]=1;
	int res=1;
	for (int i=2;i<=n;i++)
		f[i]=(3+2*f[i-1])%Mod;
	for (int i=2;i<=n;i++)
	{
		dp[i]=(dp[i-1]+f[i-1]*4%Mod*res)%Mod,
		res=res*f[i-1]%Mod;
	}//cout<<dp[n]<<endl;
	cout<<2*(dp[n]*dp[n]%Mod+1)%Mod<<endl;
	return 0;
}