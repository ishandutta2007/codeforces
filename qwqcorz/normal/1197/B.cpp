#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	if (a[i]==n)
	{
		int l=i,r=i;
		for (int j=n-1;j>=1;j--)
		{
			if (l>1&&a[l-1]==j)
			{
				l--;
				continue;
			}
			if (r<n&&a[r+1]==j)
			{
				r++;
				continue;
			}
			puts("NO");
			return 0;
		}
		puts("YES");
	}

	return 0;
}