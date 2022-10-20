#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],b[N],sum[N];
void work()
{
	ll ans=1e9+7;
	int m=read(),n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int cnt=0;
	for (int i=1;i<n;i++) if (a[i+1]!=a[i]) b[++cnt]=a[i+1]-a[i]-1;
	b[++cnt]=a[1]-1+m-a[n];
	sort(b+1,b+1+cnt);
	for (int i=1;i<=cnt;i++) sum[i]=b[i]+sum[i-1];
	for (int i=0;i<=cnt*2;i++)
	{
		int k=i/2;
		ans=min(ans,1LL*(k*2)*(k*2-1)/2+sum[cnt-k]-(i%2?(b[cnt-k]+1)/2>=i:0));
	}
	print(ans+cnt);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}