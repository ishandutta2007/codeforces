#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
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
int a[N],fact[N],inv[N],pw[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ysgs(2e5);
	int n=read(),k=read(),x=0,y=0;
	for (int i=1;i<=n;i++) a[i]=read();;a[n+1]=a[1];
	for (int i=1;i<=n;i++) if (a[i]!=a[i+1]) x++; else y++;
	int ans=power(k,x);
	for (int i=pw[0]=1;i<=n;i++) pw[i]=1LL*pw[i-1]*(k-2)%p;
	for (int i=0;i*2<=x;i++) ans=(ans+p-1LL*C(x,i*2)*C(i*2,i)%p*pw[x-i*2]%p)%p;
	ans=(p+1)/2LL*ans%p*power(k,y)%p;
	print(ans);
	
	return 0;
}