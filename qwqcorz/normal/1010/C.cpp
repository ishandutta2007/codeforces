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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}

signed main()
{
	int n=read(),k=read(),g=k;
	for (int i=1;i<=n;i++) g=gcd(read()%k,g);
	print(k/g);
	for (int i=0;i*g<k;i++) print(i*g,' ');

	return 0;
}