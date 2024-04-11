#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll f[N],a[N],b[N];

signed main()
{
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	int n=read(),c=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++)
	for (int j=i;j>=0;j--)
	{
		f[j]+=1LL*j*c+a[i];
		if (j) f[j]=min(f[j],f[j-1]+b[i]);
	}
	print(*min_element(f,f+1+n));
	
	return 0;
}