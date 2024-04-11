#include<bits/stdc++.h>
using namespace std;
const int N=1<<19;

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
int a[N];
double sum=0;

signed main()
{
	int n=read(),m=read();
	for (int i=0;i<(1<<n);i++) sum+=a[i]=read();
	printf("%.8lf\n",sum/(1<<n));
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		sum-=a[x];
		sum+=a[x]=y;
		printf("%.8lf\n",sum/(1<<n));
	}

	return 0;
}