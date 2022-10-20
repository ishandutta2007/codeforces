#include<bits/stdc++.h>
#define int long long
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
int calc(int n,int m,int x,int y)
{
	if (n==0||m==0) return 0;
	n/=x;
	m/=x;
	y/=x;
	int ret=0;
	double s=sqrt(y);
	for (int i=1;i<=s;i++)
	if (y%i==0&&gcd(i,y/i)==1)
	ret+=i<=n&&y/i<=m;
	for (int i=1;i<s;i++)
	if (y%i==0&&gcd(i,y/i)==1)
	ret+=y/i<=n&&i<=m;
	return ret;
}

signed main()
{
	int l=read(),r=read();
	int x=read(),y=read();
	if (y%x) print(0);
	else print(calc(r,r,x,y)-calc(r,l-1,x,y)-calc(l-1,r,x,y)+calc(l-1,l-1,x,y));

	return 0;
}