#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e6+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int phi[N],mn[N],h[N],s1[N],s2[N],sum0[N],sum1[N],sum2[N];
void ysgs(int n)
{
	for (int i=2;i<=n;i++) if (!mn[i])
	for (int j=i;j<=n;j+=i) if (!mn[j]) mn[j]=i;
	phi[1]=1;
	for (int i=2;i<=n;i++)
	if (i/mn[i]%mn[i]==0) phi[i]=phi[i/mn[i]]*mn[i];
	else phi[i]=phi[i/mn[i]]*(mn[i]-1);
	for (int i=1;i<=n;i++) s1[i]=(s1[i-1]+i)%p;
	for (int i=1;i<=n;i++) s2[i]=(s2[i-1]+1LL*i*i)%p;
	for (int i=1;i<=n;i++) h[i]=((1LL*i*i%p-2LL*i)*i%p+2LL*s2[i]%p-2LL*i*s1[i]%p+p+p)%p;
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j+=i) h[j]=(h[j]+2LL*phi[j/i]*i)%p;
	for (int i=1;i<=n;i++) sum0[i]=(sum0[i-1]+h[i])%p;
	for (int i=1;i<=n;i++) sum1[i]=(sum1[i-1]+1LL*h[i]*i)%p;
	for (int i=1;i<=n;i++) sum2[i]=(sum2[i-1]+1LL*h[i]*i%p*i)%p;
}

signed main()
{
	ysgs(1e6);
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),k=min(n,m);
		print((1LL*(n+1)*(m+1)%p*sum0[k]-1LL*(n+m+2)*sum1[k]%p+sum2[k]+p)%p);
	}
	
	return 0;
}