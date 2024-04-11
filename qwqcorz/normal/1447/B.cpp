#include<bits/stdc++.h>
using namespace std;
const int inf=114514;

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

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),tot1=0,tot2=0,sum1=0,sum2=0,Min1=inf,Min2=inf;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			int x=read();
			if (x<0)
			{
				tot1++;
				sum1-=x;
				Min1=min(Min1,-x);
			}
			else
			{
				tot2++;
				sum2+=x;
				Min2=min(Min2,x);
			}
		}
//		print(sum1,' ');
//		print(sum2);
//		print(Min1,',');
//		print(Min2);
		if (tot1%2==0) print(sum1+sum2);
				  else print(max(sum1-2*Min1+sum2,sum2-2*Min2+sum1));
	}

	return 0;
}