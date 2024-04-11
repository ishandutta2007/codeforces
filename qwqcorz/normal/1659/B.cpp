#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];
int f[N];
void work()
{
	int n=read(),k=read();
	scanf("%s",a+1);
	if (k&1) for (int i=1;i<=n;i++) a[i]='0'+!(a[i]-'0');
	for (int i=1;i<=n;i++) f[i]=0;
	for (int i=1;i<=n;i++) if (a[i]=='0'&&k) f[i]++,k--;
	f[n]+=k;
	for (int i=1;i<=n;i++) if (f[i]&1) a[i]='0'+!(a[i]-'0');
	puts(a+1);
	for (int i=1;i<=n;i++) print(f[i]," \n"[i==n]);
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}