//AFO countdown:8 Days
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
const int M=2e5+10;
int n,f[M],sum[M],x[M],y[M],s[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),s[i]=read();
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int tl=1,tr=i,p;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (x[Mid]>=y[i])p=Mid,tr=Mid-1;
			else tl=Mid+1;
		}f[i]=(sum[i-1]-sum[p-1]+x[i]-y[i]+2*Mod)%Mod;
		sum[i]=(sum[i-1]+f[i])%Mod;
		res=(res+s[i]*f[i])%Mod;
//		cout<<p<<' '<<f[i]<<'\n';
	}res+=x[n]+1;res%=Mod;//puts("");
	cout<<res<<endl;
	return 0;
}