#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;

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
int x[N],y[N];
bool check(int n,int k)
{
	for (int i=1;i<=n;i++)
	{
		bool flag=1;
		for (int j=1;j<=n;j++)
		if (abs(x[i]-x[j])+abs(y[i]-y[j])>k)
		flag=0;
		if (flag) return 1;
	}
	return 0;
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),k=read();
		for (int i=1;i<=n;i++)
		{
			x[i]=read();
			y[i]=read();
		}
		if (check(n,k)) puts("1");
				   else puts("-1");
	}

	return 0;
}