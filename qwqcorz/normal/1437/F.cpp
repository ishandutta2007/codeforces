#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
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
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int dp[N],sum[N],a[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	ysgs(5e3);
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	if (a[n-1]*2>a[n]) return puts("0"),0;
	dp[0]=1;
	sum[0]=fact[n-1];
	for (int i=1,j=0;i<=n;i++)
	{
		while (a[j+1]*2<=a[i]) j++;
		dp[i]=1LL*sum[j]*inv[n-j-1]%p;
		if (i<n) sum[i]=(sum[i-1]+1LL*dp[i]*fact[n-j-2])%p;
	}
	print(dp[n]);
	
	return 0;
}