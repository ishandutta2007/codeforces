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

const int M=1e6+10;
int n,q,a[M],prime[M],f[M],t[M],t1[M],cnt;

signed main()
{
	for (int i=2;i<=1e6;i++)
	{
		if (f[i])continue;
		prime[++cnt]=i;
		for (int j=i*i;j<=1e6;j+=i)
			f[j]=1;
	}
	WT
	{
		n=read();int ans1=0,ans2=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			for (int j=1;j<=cnt&&prime[j]*prime[j]<=a[i];j++)
				while(a[i]%(prime[j]*prime[j])==0)
					a[i]/=prime[j]*prime[j];
			t[a[i]]++;
		}q=read();
		for (int i=1;i<=n;i++)
		{
			if (t1[a[i]])continue;
			t1[a[i]]=1;ans1=max(ans1,t[a[i]]);
			if (t[a[i]]&1)continue;
			ans2+=t[a[i]];
		}if (t[1]&1)ans2+=t[1];
		while(q--)
		{
			int w=read();
			if (w==0)cout<<ans1<<endl;
			else cout<<max(ans1,ans2)<<endl;
		}
		for (int i=1;i<=n;i++)t[a[i]]=t1[a[i]]=0;
	}
	return 0;
}