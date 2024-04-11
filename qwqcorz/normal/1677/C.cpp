#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N];
int p[N],to[N];
void work()
{
	int n=read(),m=0;
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) to[p[i]]=read();
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++)
	{
		int tot=0;
		for (int j=i;!vis[j];j=to[j]) vis[j]=1,tot++;
		m+=tot&1;
	}
	ll ans=0;
	for (int i=1;i<=(n-m)/2;i++) ans+=(n-i+1)*2-i*2;
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}