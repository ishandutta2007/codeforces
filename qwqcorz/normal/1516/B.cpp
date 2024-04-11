#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],l[N],r[N];
bool Metallica()
{
	int n=read(),sum=0;
	for (int i=1;i<=n;i++) sum^=a[i]=read();
	if (!sum) return 1;
	l[0]=r[n+1]=0;
	for (int i=1;i<=n;i++) l[i]=l[i-1]^a[i];
	for (int i=n;i>=1;i--) r[i]=r[i+1]^a[i];
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	if (l[i]==sum&&r[j]==sum) return 1;
	return 0;
}

signed main()
{
	int T=read();
	while (T--) puts(Metallica()?"YES":"NO");
	
	return 0;
}