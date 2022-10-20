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
map<int,int>a;

signed main()
{
	a.clear();
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[x]++;
	}
	int Max=0;
	for (map<int,int>::iterator i=a.begin();i!=a.end();i++)
	Max=max(Max,i->second);
	print(n-Max);

	return 0;
}