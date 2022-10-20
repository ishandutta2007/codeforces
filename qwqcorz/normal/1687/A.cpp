#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
ll sum[N];
void work()
{
	int n=read(),k=read(),tot=min(k,n);
	ll ans=1LL*(k-1+k-tot)*tot/2,mx=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=tot;i<=n;i++) mx=max(mx,sum[i]-sum[i-tot]);
	print(mx+ans);
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}