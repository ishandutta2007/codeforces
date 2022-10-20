#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int WCR=2333;

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
const int p[12]={0,2,3,5,7,11,13,17,19,23,29,31};
int a[N],b[12];

int main()
{
	int t=read();
	while (t--)
	{
		for (int i=1;i<=11;i++) b[i]=0;
		int n=read(),m=0;
		for (int i=1;i<=n;i++)
		{
			int x=read();
			for (int j=1;j<=11;j++)
			if (x%p[j]==0)
			{
				if (!b[j]) b[j]=++m;
				a[i]=b[j];
				break;
			}
		}
		print(m);
		for (int i=1;i<=n;i++) print(a[i],' ');
		putchar('\n');
	}

	return 0;
}