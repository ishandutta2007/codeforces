#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
const int Mod=998244353;
int n,m,d[M],sum[M];

bool cmp(int a,int b){return a>b;}

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)d[i]=read();
	sort(d+1,d+1+n,cmp);
	for (int i=1;i<=n;i++)sum[i]=(sum[i-1]+d[i])%Mod;
	for (int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		int tl=1,tr=n,p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (d[Mid]>=b)tl=Mid+1,p=Mid;
			else tr=Mid-1;
		}int cnt=p;//cout<<cnt<<' ';
		if (cnt<a){puts("0");continue;}
		int ans=sum[cnt]*(cnt-a)%Mod*poww(cnt,Mod-2)%Mod;
		ans+=(sum[n]-sum[cnt])*(cnt+1-a)%Mod*poww(cnt+1,Mod-2)%Mod;
		ans%=Mod,ans+=Mod,ans%=Mod;
		cout<<ans<<endl;
	}
	return 0;
}