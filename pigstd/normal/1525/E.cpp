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
const int M=5e4+10;
const int N=25;
int n,m,d[N][M],ans,a[N],t[M],fac[N];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

int inv(int x)
{
	return poww(x,Mod-2);
}

void init()
{
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod;
}

int solve()
{
	int res=1,cnt=0;
	for (int i=0;i<=n;i++)t[i]=0;
	for (int i=1;i<=n;i++)t[a[i]]++;
	for (int i=n;i>=1;i--)
		cnt+=t[i],res=res*max(0ll,cnt)%Mod,cnt--;
//	cout<<res<<' '; 
	return res*inv(fac[n])%Mod;
}

signed main()
{
	n=read(),m=read();init();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			d[i][j]=read()-1;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)a[j]=d[j][i];
		sort(a+1,a+1+n);ans+=(1+Mod-solve()),ans%=Mod;
	}cout<<ans<<endl;
	return 0;
}