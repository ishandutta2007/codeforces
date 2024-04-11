//AFO countdown:10 Days
#include<bits/stdc++.h>
//#define int long long
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

const int Mod=31607;
const int M=25;
const int N=(1<<21)+10;
int n,a[M][M],b[M][M],f1[N],f2[M][N],lg2[N],Inv[M][M];

int lowbit(int x){return x&(-x);}
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

void clear()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)b[i][j]=a[i][j]; 
}

int work()
{
	int res=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)Inv[i][j]=inv(b[i][j]);
	for (int i=1;i<=n;i++)
	{
		f1[i]=1;
		for (int j=1;j<=n;j++)
			f1[i]=f1[i]*b[i][j]%Mod;
	}
	for (int i=1;i<=n;i++)
	{
		f2[i][0]=1;
		for (int j=1;j<=n;j++)
			f2[i][0]=f2[i][0]*b[j][i]%Mod;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<(1<<n);j++)
			f2[i][j]=f2[i][lowbit(j)^j]*Inv[lg2[lowbit(j)]][i]%Mod;
	for (int i=0;i<(1<<n);i++)
	{
		int cnt=0,p=1;
		for (int j=1;j<=n;j++)
			if (i&(1<<(j-1)))cnt++,p=p*f1[j]%Mod;
		for (int j=1;j<=n;j++)
			p=p*(1-f2[j][i]+Mod)%Mod;
		res=(res+((cnt&1)?-1:1)*p+Mod)%Mod; 
	}return res;
}

signed main()
{
	n=read();
	for (int i=1;i<(1<<n);i<<=1)
		lg2[i]=lg2[i>>1]+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			b[i][j]=a[i][j]=read()*inv(10000)%Mod;
	int res=work(),p=1;
	for (int i=1;i<=n;i++)p=p*b[i][i]%Mod,b[i][i]=1;
	res=(res-p*work()%Mod+Mod)%Mod;clear();p=1;
	for (int i=1;i<=n;i++)p=p*b[i][n-i+1]%Mod,b[i][n-i+1]=1;
	res=(res-work()*p%Mod+Mod)%Mod;clear();p=1;
	for (int i=1;i<=n;i++)
	{
		p=p*b[i][i]%Mod;
		if (i!=n-i+1)p=p*b[i][n-i+1]%Mod;
		b[i][i]=b[i][n-i+1]=1;
	}
	res=(res+work()*p)%Mod;
	res=(1-res+Mod)%Mod;cout<<res<<endl;
	return 0;
}