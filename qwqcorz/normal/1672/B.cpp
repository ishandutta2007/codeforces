#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];
bool work()
{
	scanf("%s",a+1);
	int n=strlen(a+1),sum=0;
	for (int i=1;i<=n;i++) if ((sum+=a[i]=='A'?1:-1)<0) return 0;
	return a[n]=='B';
}

signed main()
{
	int T=read();
	while (T--) puts(work()?"YES":"NO");
	
	return 0;
}