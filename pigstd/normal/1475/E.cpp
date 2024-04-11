#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=1e3+10;
int a[M],n,fac[M],inv[M],t[M];

bool cmp(int a,int b){return a>b;}

int poww(int a,int b)
{
	int r=1;
	while(b)
	{
		if (b&1)r=r*a%Mod;
		a=a*a%Mod,b>>=1;
	}
	return r;
}

void init()
{
	fac[0]=inv[0]=1;
	for (int i=1;i<=1e3;i++)
		fac[i]=fac[i-1]*i%Mod,inv[i]=poww(fac[i],Mod-2);
}

int C(int m,int n)
{
	return fac[m]*inv[n]%Mod*inv[m-n]%Mod;
}

signed main()
{
	int T=read();init();
	while(T--)
	{
		n=read();int k=read();
		for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
		sort(a+1,a+1+n,cmp);int p;
		for (int i=1;i<=k;i++)
			if (a[i]==a[k]){p=k-i+1;break;}
		cout<<C(t[a[k]],p)<<endl;
		for (int i=1;i<=n;i++)t[a[i]]--;
	}
}