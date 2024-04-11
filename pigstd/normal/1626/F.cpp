#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int N=12252240;
int dp[2][N+10],n,x,y,M,k,a,cnt,res,C[20][20],pw[20],pw2[20];

inline int f(int x){return (x>=Mod?x-Mod:x);}

void init_C(int n)
{
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=f(C[i-1][j-1]+C[i-1][j]);
	}
}

signed main()
{
	n=read(),a=read(),x=read(),y=read(),k=read(),M=read();int r=0;init_C(k);
	dp[0][a%N]=1,cnt=a/N;for (int i=1;i<n;i++)a=(1ll*a*x+y)%M,cnt+=a/N,dp[0][a%N]++;
	pw[0]=pw2[0]=1;
	for (int i=1;i<=k;i++)pw[i]=1ll*pw[i-1]*(n-1)%Mod,pw2[i]=1ll*pw2[i-1]*n%Mod;
	for (int j=1;j<=k;j++)
	{
		r^=1;for (int i=0;i<N;i++)dp[r][i]=1ll*dp[r^1][i]*(n-1)%Mod;
		for (int i=0;i<N;i++)
			res=(1ll*dp[r^1][i]*i%Mod*pw2[k-j]+res)%Mod,
			dp[r][i/j*j]=f(dp[r][i/j*j]+dp[r^1][i]);
	}
	for (int i=1;i<=k;i++)res=(res+1ll*cnt*i%Mod*N%Mod*C[k][i]%Mod*pw[k-i])%Mod;
	cout<<res<<'\n';
	return 0;
}