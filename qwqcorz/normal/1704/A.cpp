#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=55;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N],b[N];
void work()
{
	int n=read(),m=read(),tot[2]={};
	scanf("%s%s",a+1,b+1);
	for (int i=1;i<=n-m+1;i++) tot[a[i]-'0']++;
	for (int i=2;i<=m;i++) if (a[n-m+i]!=b[i]) return puts("NO"),void();
	puts(tot[b[1]-'0']?"YES":"NO");
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}