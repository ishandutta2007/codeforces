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
bool a[N];

int main()
{
	int T=read();
	while (T--)
	{
		int m=read(),n=0;
		char c=getchar();
		while (c<'0'||'9'<c) c=getchar();
		while ('0'<=c&&c<='9') a[++n]=c-'0',c=getchar();
		int l=0,r=0;
		for (int i=n;i>=1;i--) if (a[i]==1) l=i;
		for (int i=1;i<=n;i++) if (a[i]==0) r=i;
		if (l==0||r==0)
		{
			for (int i=1;i<=n;i++) putchar(a[i]+'0');
			putchar('\n');
		}
		else
		{
			for (int i=1;i<l;i++) putchar(a[i]+'0');
			if (l<r) putchar('0');
			for (int i=r+1;i<=n;i++) putchar(a[i]+'0');
			putchar('\n');
		}
	}

	return 0;
}