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
int a[233];

signed main()
{
	int n=read(),k=read(),Max=0,ans=0;
	for (int i=1;i<=n;i++) a[read()]++;
	for (int i=1;i<=100;i++) Max=max(Max,a[i]);
	Max=(Max/k+(Max%k>0))*k;
	for (int i=1;i<=100;i++)
	if (a[i])
	ans+=Max-a[i];
	print(ans);

	return 0;
}