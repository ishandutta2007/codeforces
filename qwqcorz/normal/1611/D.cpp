#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int fa[N],p[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) fa[i]=read();
	for (int i=1;i<=n;i++) p[read()]=i;
	for (int i=1;i<=n;i++) if (p[i]<p[fa[i]]) return puts("-1"),void();
	for (int i=1;i<=n;i++) print(p[i]-p[fa[i]]," \n"[i==n]);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}