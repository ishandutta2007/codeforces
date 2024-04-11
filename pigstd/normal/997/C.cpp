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

const int Mod=998244353;
const int M=1e6+10;
int n,fac[M],ifac[M];

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
int C(int m,int n){return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}
void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod,ifac[i]=ifac[i-1]*inv(i)%Mod;
}

signed main()
{
	n=read();init(n);int res=poww(poww(3,n)-3,n);
	for (int i=1;i<=n;i++)
	{
		int sum=((poww(3,i)-3)*poww(3,(n-i)*n)+3*poww(poww(3,n-i)-1,n))%Mod;
		res=(res+((i&1)?Mod-1:1)*sum%Mod*C(n,i))%Mod;
	}
	res=(poww(3,n*n)-res+Mod)%Mod;
	cout<<res<<endl;
	return 0;
}