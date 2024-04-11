#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int p[N],f[N],g[N],dp[N],n;
void update(int i)
{
	if (i>n) return;
	int inc=0,dec=n+1;
	if (p[i-1]<p[i]) inc=max(inc,f[i-1]);
	if (g[i-1]<p[i]) inc=max(inc,p[i-1]);
	if (p[i-1]>p[i]) dec=min(dec,g[i-1]);
	if (f[i-1]>p[i]) dec=min(dec,p[i-1]);
	if (inc==f[i]&&dec==g[i]) return;
	f[i]=inc,g[i]=dec;
	update(i+1);
	dp[i]=dp[i+1]+(inc>0||dec<=n);
}

signed main()
{
	ll ans=0;
	n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=n;i>=1;i--)
	{
		f[i]=n+1,g[i]=0;
		update(i+1);
		dp[i]=dp[i+1]+1;
		ans+=dp[i];
	}
	print(ans);
	
	return 0;
}