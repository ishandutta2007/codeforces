#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
int a[N],b[N],c[N],d[N];

signed main()
{
	int T=read();
	while (T--)
	{
		bool flag1=0,flag2=0,flag3=0;
		int n=read(),m=read();
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			b[i]=read();
			c[i]=read();
			d[i]=read();
			flag1|=a[i]==d[i]&&b[i]==c[i];
			flag2|=b[i]==c[i];
		}
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		flag3|=a[i]==a[j]&&d[i]==d[j]&&b[i]==c[j]&&c[i]==b[j];
		puts((flag1||(flag2&&flag3))&&(m%2==0)?"YES":"NO");
	}

	return 0;
}