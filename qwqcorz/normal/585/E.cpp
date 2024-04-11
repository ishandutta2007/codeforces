#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=1e7+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int f[N],g[N],a[M],mu[M];

signed main()
{
	int n=read(),m=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[x]++;
		m=max(m,x);
	}
	for (int i=g[0]=1;i<=n;i++)
		g[i]=2LL*g[i-1]%p,
		f[i]=(2LL*f[i-1]+g[i-1])%p;
	for (int i=mu[1]=1;i<=m;i++)
	{
		for (int j=i+i;j<=m;j+=i) mu[j]-=mu[i],a[i]+=a[j];
		ans=(ans+mu[i]*(2LL*f[a[i]]-1LL*(g[a[i]]-1)*n)%p+p)%p;
	}
	print(ans);
	
	return 0;
}