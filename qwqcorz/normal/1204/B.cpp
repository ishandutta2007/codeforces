#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int n,l,r,a[N];
int Min()
{
	a[1]=1;
	for (int i=2;i<=l;i++) a[i]=a[i-1]*2;
	for (int i=l+1;i<=n;i++) a[i]=1;
	int ret=0;
	for (int i=1;i<=n;i++) ret+=a[i];
	return ret;
}
int Max()
{
	a[1]=1;
	for (int i=2;i<=r;i++) a[i]=a[i-1]*2;
	for (int i=r+1;i<=n;i++) a[i]=a[i-1];
	int ret=0;
	for (int i=1;i<=n;i++) ret+=a[i];
	return ret;
}

signed main()
{
	n=read();
	l=read();
	r=read();
	print(Min(),' ');
	print(Max());

	return 0;
}