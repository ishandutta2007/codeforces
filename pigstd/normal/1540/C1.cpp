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

const int Mod=1e9+7;
const int M=110;
int dp[M][M*M],n,d[M],c[M],s[M],sc[M];

void solve(int x)
{
	s[1]=x;
	for (int i=2;i<=n;i++)s[i]=s[i-1]+d[i-1];
	for (int i=1;i<=n;i++)s[i]+=s[i-1];
	dp[0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=sc[i];j++)
			for (int k=max(0ll,s[i+1]-j);k<=c[i+1];k++)
				dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j])%Mod;
	int ans=0;
	for (int i=max(s[n],0ll);i<=sc[n];i++)ans=(ans+dp[n][i])%Mod;
	cout<<ans<<endl;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)sc[i]=c[i]=read(),sc[i]+=sc[i-1];
	for (int i=1;i<n;i++)d[i]=read();
	WT{solve(read());}
	return 0;
}