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

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),k=read();
		if (n%2==0) print((k-1)%n+1);
		else print((k+(k-1)/(n/2)-1)%n+1);
//		else print((k-1)%(n-1)+1+(((k-1)%(n-1)+1)*2-1>=n-(k-1)/(n-1)*(n-1)%n));
	}

	return 0;
}