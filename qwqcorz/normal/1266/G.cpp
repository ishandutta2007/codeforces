#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int p=998244353;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int fact[N],inv[N],f[N*2];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),ans=0;
	ysgs(n);
	f[0]=n;
	int l=1LL*fact[n]*n%p;
	for (int i=1;i<n;i++) f[i]=fact[n]*(1LL*(n-i)*(n-i)%p+1)%p*inv[n-i+1]%p;
	for (int i=n;i<n*2;i++) f[i]=(fact[n]-f[i-n]+p)%p;
	for (int i=1;i<n*2;i++) ans=(ans+1LL*f[i]*i)%p;
	print((l*(l+1LL)/2-ans)%p);
	
	return 0;
}