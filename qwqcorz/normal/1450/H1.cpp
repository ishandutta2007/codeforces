#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int p=998244353;
const int inv2=(p+1)/2;

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
int C(int n,int m)
{
	if (n<0||m<0||n<m) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}
char a[N];
int solve(int c,int c0,int c1)
{
	int ans=0;
	for (int i=-c1;i<=c0;i++) if ((c+i)%2==0) ans=(ans+1LL*abs(c+i)*C(c0+c1,c1+i))%p;
	return 1LL*ans*power(inv2,c0+c1)%p;
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),m=read(),c=0,c0=0,c1=0;
	scanf("%s",a+1);
	ysgs(n),void(m);
	for (int i=1;i<=n;i++)
	if (a[i]=='b') i%2?c--:c++;
	else if (a[i]=='?') (i%2?c1:c0)++;
	print(solve(c,c0,c1));
	
	return 0;
}