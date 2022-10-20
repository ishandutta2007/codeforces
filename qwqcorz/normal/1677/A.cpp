#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int p[N],a[N],sum[N],tot[N];
void work()
{
	ll ans=0;
	int n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=0;i<=n+1;i++) sum[i]=tot[i]=a[i]=0;
	for (int i=n;i>=1;i--)
	{
		for (int j=i+1;j<=n;j++) if (p[i]<p[j]) ans+=sum[j+1]-tot[j];
		for (int j=i+1;j<=n;j++) if (p[i]>p[j]) a[j]++;
		for (int j=n;j>=i;j--) sum[j]=sum[j+1]+a[j];
		tot[i]=sum[i];
	}
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}