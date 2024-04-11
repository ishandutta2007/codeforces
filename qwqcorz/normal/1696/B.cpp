#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
void work()
{
	int n=read(),tot=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) tot+=!a[i];
	if (tot==n) return puts("0"),void();
	int ans=0;
	for (int i=1,flag=0;i<=n+1;i++)
	if (i<=n&&a[i]) flag=1;
			   else ans+=flag,flag=0;
	print(ans==1?1:2);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}