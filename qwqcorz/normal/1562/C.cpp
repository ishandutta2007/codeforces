#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;

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
char a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),flag=0;
		scanf("%s",a+1);
		for (int i=1;i<=n;i++)
		if (a[i]=='0')
		{
			if (i<=n/2) print(i,' '),print(n,' '),print(i+1,' '),print(n);
				   else print(1,' '),print(i,' '),print(1,' '),print(i-1);
			flag=1;
			break;
		}
		if (flag) continue;
		print(1,' '),print(n/2,' ');
		print(n-n/2+1,' '),print(n);
	}
	
	return 0;
}