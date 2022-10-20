#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
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
		if (b&1) ret=ret*a%p;
		b/=2;
		a=a*a%p;
	}
	return ret;
}
int C(int n)
{
	int fact=1,inv=1;
	for (int i=1;i<=n;i++) fact=fact*i%p;
	inv=power(fact,p-2);
	for (int i=n+1;i<=n*2;i++) fact=fact*i%p;
	return fact*inv%p*inv%p;
}
int a[N];

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n*2;i++) a[i]=read();
	sort(a+1,a+1+n*2);
	for (int i=1;i<=n;i++) ans+=a[i+n]-a[i];
	ans%=p;
	ans=ans*C(n)%p;
	print(ans);

	return 0;
}