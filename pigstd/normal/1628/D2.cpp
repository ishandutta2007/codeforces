#include<bits/stdc++.h>
#define int long long
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

const int Mod=1e9+7;
const int M=1e6+10;
int n,inv[M],fac[M],ifac[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void init_inv(int n)
{
	inv[1]=1;
	for (int i=2;i<=n;i++)
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
}

void init_C(int n)
{
	init_inv(n);
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=ifac[i-1]*inv[i]%Mod;
}

int C(int m,int n)
{
	if (n<0||m<n)return 0;
	return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;
}

signed main()
{
	init_C(1e6);
	WT
	{
		int n=read(),m=read(),k=read();
		if (n==m){cout<<m*k%Mod<<'\n';continue;}
		int res=0;
		for (int i=1;i<=m;i++)
			res=(res+C(n-i-1,m-i)*i%Mod*poww(inv[2],n-i))%Mod;
		cout<<res*k%Mod<<'\n';
	}
	return 0;
}
/*
dp[i][j] 

dp[1][0]=0,
dp[1][1]=1,

dp[i][j] = max(min(dp[i-1][j-1]+x,dp[i-1][j]-x))
 dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])/2 

*/