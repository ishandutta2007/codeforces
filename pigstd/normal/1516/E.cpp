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

const int Mod=1e9+7;
const int M=410;
int n,k,f[M][M],g[M][M],fac1[M],ifac[M],fac2[M];

int C(int k){return fac2[k]*ifac[k]%Mod;}
int C(int m,int n){return fac1[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void init(int n,int k)
{
	fac1[0]=ifac[0]=1,fac2[0]=1;
	for (int i=1;i<=min(n,2*k);i++)
		fac1[i]=fac1[i-1]*i%Mod,
		ifac[i]=poww(fac1[i],Mod-2),
		fac2[i]=fac2[i-1]*(n-i+1)%Mod;
}

signed main()
{
	n=read(),k=read();init(n,k);f[0][0]=1;
	for (int i=1;i<=min(n,2*k);i++)
	{
		f[i][0]=1;
		for (int j=1;j<=min(2*k,n);j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-1]*(i-1))%Mod;
	}
	for (int i=0;i<=min(n,2*k);i++)
		for (int j=0;j<=k;j++)
			for (int ff=0;ff<=i;ff++)
				g[i][j]=(g[i][j]+((ff&1)?-1:1)*f[i-ff][j]*C(i,ff))%Mod;
//	for (int i=0;i<=n;i++)
//		for (int j=0;j<=n;j++)
//			cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
	for (int i=1;i<=k;i++)
	{
		int ans=0;
		for (int j=min(2*i,n);j>=0;j--)
		{
			int sum=0;
			for (int p=i;p>=0;p-=2)
				sum=(sum+g[j][p])%Mod;
			sum=sum*C(j)%Mod;ans=(ans+sum)%Mod;
		}
		ans=(ans+Mod)%Mod;
		cout<<ans<<' ';
	}
	return 0;
}
// 2 3