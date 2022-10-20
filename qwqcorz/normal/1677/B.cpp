#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N];
int a[N],sum[N],x[N],y[N];
void work()
{
	int n=read(),m=read(),tot=0;
	scanf("%s",s+1);
	for (int i=0;i<=n*m;i++) a[i]=s[i]=='1',sum[i]=x[i]=y[i]=0;
	for (int i=1;i<=n*m;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]) tot+=!y[i%m],y[i%m]=1;
		x[i]=x[max(i-m,0)]+!!(sum[i]-sum[max(i-m,0)]);
		print(x[i]+tot," \n"[i==n*m]);
	}
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}