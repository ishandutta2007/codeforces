#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
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
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
char a[N];
int fact[N],inv[N];
int C(int n,int m)
{
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}

signed main()
{
	for (int i=fact[0]=1;i<N;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[N-1]=power(fact[N-1],p-2);
	for (int i=N-1;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
	int T=read();
	while (T--)
	{
		int n=read(),now=0,tot1=0,tot0=-1;
		scanf("%s",a+1),a[n+1]='0';
		for (int i=1;i<=n+1;i++)
		if (a[i]=='0') tot1+=now/2,now=0,tot0++;
				  else now++;
		print(C(tot0+tot1,tot0));
	}

	return 0;
}