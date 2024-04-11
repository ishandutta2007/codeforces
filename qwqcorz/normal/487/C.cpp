#include<bits/stdc++.h>
using namespace std;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
bool prime(int x)
{
	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return 0;
	return 1;
}
int power(int a,int b,int p)
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

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	if (n==1) puts("YES\n1");
	else if (n==4) puts("YES\n1\n3\n2\n4");
	else if (prime(n))
	{
		puts("YES");
		print(1);
		for (int i=1;i<=n-2;i++) print(1LL*i*power(i+1,n-2,n)%n);
		print(n);
	}
	else puts("NO");

	return 0;
}