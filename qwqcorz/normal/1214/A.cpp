#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool f[N];

signed main()
{
	int n=read(),d=read(),e=read()*5,m=d*e,k=max(n/m-1,0);
	n-=k*m;
	f[0]=1;
	for (int i=d;i<=n;i++) f[i]|=f[i-d];
	for (int i=e;i<=n;i++) f[i]|=f[i-e];
	for (int i=n;i>=0;i--) if (f[i]) return print(n-i),0;
	
	return 0;
}