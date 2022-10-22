#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Mod=1e9+7;
const int M=5e3+10;
int n,ans,k,s[M][M],dfac[M];

int poww(int a,int b)
{
	int r=1;
	while(b)
	{
		if (b&1)r=r*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return r;
}

int fac[M],inv[M];

void init()
{
	fac[0]=1;
	for (int i=1;i<M;i++)fac[i]=fac[i-1]*i%Mod;
	for (int i=0;i<M;i++)inv[i]=poww(fac[i],Mod-2);
}

int p=Mod;
int C(int m,int n)
{
	return fac[m]*inv[m-n]%p*inv[n]%p;
}

signed main()
{
	cin>>n>>k;s[0][0]=1;
	if (k>=n)
	{
		init();
		for (int i=1;i<=n;i++)ans=(ans+C(n,i)*poww(i,k))%Mod;cout<<ans;
		return 0;
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+j*s[i-1][j]%Mod)%Mod;//cout<<s[i][j]<<' ';
//		puts("");
	}
	dfac[0]=1;
	for (int i=1;i<=k;i++)dfac[i]=dfac[i-1]*(n-i+1)%Mod;
	for (int i=0;i<=k;i++)
		ans=(ans+s[k][i]*dfac[i]%Mod*poww(2,n-i)%Mod)%Mod;
	cout<<ans;
	return 0;
}