#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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
const int M=4e5+10;
int n,k,cnt,sa[M],rk[M],ans;
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
int C(int m,int n)
{
	if (n<0||m<0||n>m)return 0;
	return fac[m]*ifac[m-n]%Mod*ifac[n]%Mod;
}

void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=inv(fac[i]);
}

signed main()
{
	n=read(),k=read();init(n+k);
	for (int i=1;i<=n;i++)sa[i]=read()+1,rk[sa[i]]=i;
	for (int i=1;i<n;i++)
		if (rk[sa[i]+1]<rk[sa[i+1]+1])cnt++;
	cout<<C(cnt+k,n)<<endl;
	return 0;
}