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
char a[N];

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	for (int i=1;i<=5;i++)
	if (i*20>=n)
	for (int j=0;j<5;j++)
	if ((n+j)%i==0)
	{
		int m=(n+j)/i,cnt=0;
		print(i,' ');
		print(m);
		for (int k=1;k<=i;k++)
		{
			if (k<=j) putchar('*');
			for (int t=1;t<=m-(k<=j);t++) putchar(a[++cnt]);
			puts("");
		}
		return 0;
	}

	return 0;
}