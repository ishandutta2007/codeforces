#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int tot[N],a[N],b[N];
bool work()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++) tot[i]=0;
	for (int i=1,j=1;i<=n;i++)
	{
		while (j<=n&&b[i]!=a[j]) tot[a[j++]]++;
		if (j>n) return 0;
		if (tot[b[i]]) tot[b[i]]--;
				  else j++;
	}
	return 1;
}

signed main()
{
	int T=read();
	while (T--) puts(work()?"YES":"NO");
	
	return 0;
}