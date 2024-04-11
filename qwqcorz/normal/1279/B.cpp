#include<bits/stdc++.h>
#define int long long
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),s=read(),ans=0,sum=0,mx=0,j=0;
		for (int i=1;i<=n;i++)
		{
			int x=read();
			sum+=x;
			if (x>mx) mx=x,j=i;
			if (sum-mx<=s) ans=j;
		}
		if (sum<=s) puts("0");
			   else print(ans);
	}
	
	return 0;
}