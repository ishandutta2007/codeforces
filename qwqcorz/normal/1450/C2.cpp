#include<bits/stdc++.h>
using namespace std;
const int N=3e2+5;

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
char get()
{
	char c=getchar();
	while (c!='.'&&c!='O'&&c!='X') c=getchar();
	return c;
}
char a[N][N];
int calc(int n,int k)
{
	int ret=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	ret+=(a[i][j]=='O'&&((i-j)%3+3)%3==k)||(a[i][j]=='X'&&((i-j)%3+4)%3==k);
	return ret;
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),cnt=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		cnt+=(a[i][j]=get())!='.';
		for (int k=0;k<=2;k++)
		if (calc(n,k)<=cnt/3)
		{
			for (int i=1;i<=n;i++,putchar('\n'))
			for (int j=1;j<=n;j++)
			{
				if (a[i][j]=='.') putchar('.');
				if (a[i][j]=='O') putchar(((i-j)%3+3)%3==k?'X':'O');
				if (a[i][j]=='X') putchar(((i-j)%3+4)%3==k?'O':'X');
			}
			break;
		}
	}

	return 0;
}