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
const int M=2e5+10;
int n,t,a[M],s[M],ans,f[M],p[M];
int fac[M],ifac[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

int inv(int x){return poww(x,Mod-2);}

void init(int x)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=x;i++)
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=inv(fac[i]);
}

int C(int m,int n)
{
	if (n>m)return 0;
	return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;
}

signed main()
{
	n=read(),t=read();init(2e5);
	for (int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++)
	{
		int x=min(i,t-s[i]);p[i]=t-s[i];
		if (x<0)break;
		if (i==1)
		{
			for (int j=0;j<=x;j++)
				f[i]=(f[i]+C(i,j))%Mod;
		}
		else
		{
			f[i]=(2*f[i-1]-C(i-1,p[i-1]))%Mod;
			for (int j=min(p[i-1],i);j>p[i];j--)
				f[i]=(f[i]-C(i,j)+Mod)%Mod;
		}
//		cout<<f[i]<<' ';
	}//puts("");
	for (int i=n;i>=1;i--)
		ans=(ans+f[i]*poww(2,n-i))%Mod;
	ans=ans*inv(poww(2,n))%Mod;
	cout<<ans<<endl;
	return 0;
}
/*

*/