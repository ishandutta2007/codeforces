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

const int Mod=998244353;
const int M=3e5+10;
int fac[M],ifac[M],f[M],g[M],n,a[M],t[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}
int Inv(int x){return poww(x,Mod-2);}

int C(int m,int n){return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

signed main()
{
	n=read();
	ifac[0]=fac[0]=1;
	for (int i=1;i<=3e5;i++) 
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=Inv(fac[i]);
	for (int i=1;i<=n;i++)
		a[i]=read(),t[a[i]]++;
	int k=a[1];for (int i=2;i<=n;i++)k=__gcd(k,a[i]);
	if (k!=1)return puts("-1"),0;
	for (int i=1;i<=7;i++)
	{
		for (int j=3e5;j>=1;j--)
		{
			int cnt=0;
			for (int k=j;k<=3e5;k+=j)
				cnt+=t[k];
			f[j]=C(cnt,i);
		}
		for (int j=3e5;j>=1;j--)
		{
			g[j]=f[j];
			for (int k=j*2;k<=3e5;k+=j)
				g[j]=(g[j]-g[k]+Mod)%Mod;
		}
		if (g[1]){cout<<i<<endl;return 0;}
	}
	return 0;
}