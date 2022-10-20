#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
void L(int x)
{
	putchar('L');
	putchar(' ');
	print(x);
}
void R(int x)
{
	putchar('R');
	putchar(' ');
	print(x);
}
char a[N];

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	print(4);
	L(2);
	L(2);
	R(2);
	R(n+2+n-1);

	return 0;
}