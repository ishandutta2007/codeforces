#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int v[N];
void work()
{
	ll ans=1;
	int n=read(),k=read();
	for (int i=1;i<=n;i++) v[i]=read();
	for (int i=n-k+1;i<=n;i++) if (v[i]>0) ans=0;
	for (int i=1;i<=k;i++) ans=1LL*ans*i%p;
	for (int i=1;i<=n-k;i++)
	{
		int pos=i+k;
		if (v[i]==0) ans=1LL*ans*(k+1)%p;
		if (v[i]<0) ans=1LL*ans*pos%p;
	}
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}