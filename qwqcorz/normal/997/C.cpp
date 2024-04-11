#include<bits/stdc++.h>
#define int long long
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
	a%=p;
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<0||m<0||n<m) return 0;
	return fact[n]*inv[m]%p*inv[n-m]%p;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	ysgs(1e6);
	int n=read();
	int ans=(power(3,n*n)-power(power(3,n)+p-3,n)+p)%p;
	for (int i=1;i<=n;i++)
	ans=(ans-C(n,i)*(i%2?-1:1)*((power(3,i)+p-3)*power(3,n*(n-i))%p+3*power(power(3,n-i)+p-1,n)%p)%p)%p;
	print((ans%p+p)%p);
	
	return 0;
}