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
const int M=2e5+10;
int a[M],sum[M],sum1[M],sum2[M],ns,n,ans;

void work(int x,int opt,int opt1)
{
	if (x<0)return;
	if (!opt1)ans=(ans+1)%Mod;
	for (int i=2-opt1;i<=n-1;i++)
	{
		int ns=sum[i]-a[1];
		if (ns>x)return;
		ns=x-ns;
		int tl=0,tr=(n-1-i)/2,p;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			int pm=Mid*2+i;
			if (sum1[pm]+sum2[pm]-sum1[i]-sum2[i]<=ns)p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}
		if (i+p*2==n-1&&opt&&p!=0)p--;
		ans=(ans+p+1)%Mod;
	}
}

signed main()
{
	WT
	{
		n=read();ans=0;
		if (n==2)
		{
			a[1]=read(),a[2]=read();
			if (a[1]==a[2])puts("1");
			else puts("2");
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			a[i]=read(),sum[i]=sum[i-1]+a[i];
			if ((i&1)&&i>=3)sum1[i]=sum1[i-2]+a[i];
			else if ((i&1)&&i==1)sum1[i]=a[i];
			else sum2[i]=sum2[i-2]+a[i];
		}ns=(sum[n]-1)/2;
		work(ns,0,0);
		work(ns-a[1],0,1);
		work(ns-a[n],1,0);
		work(ns-a[n]-a[1],1,1);
		for (int i=n-1;i>=3;i--)
			if (sum[n]-sum[i-1]<=ns)ans=(ans+1)%Mod;
//		for (int i=n-1;i>=4;i--)
//			if (sum[n]-sum[i-1]+a[1]<=ns)ans=(ans+1)%Mod;
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
5
35312300 400631070 816517490 423172884 519720373
ans:12
*/