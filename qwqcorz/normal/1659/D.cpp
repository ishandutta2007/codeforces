#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],c[N];
void work()
{
	int n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=n;i++) a[i]=1;
	for (int i=1,r=0;i<=n;i++)
	{
		if (r<i) a[i]=!!c[i];
		if (r<i&&!c[i]) continue;
		a[r=i+(c[i]-a[i]*(i-1))]=0;
	}
	for (int i=1;i<=n;i++) print(a[i]," \n"[i==n]);
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}