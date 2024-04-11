#include<bits/stdc++.h>
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
	int n=read(),m=read();
	if (n==1&&m==1) return puts("0"),0;
	if (m==1)
	{
		for (int i=1;i<=n;i++) print(i+1);
		return 0;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	print(i*(j+n)," \n"[j==m]);
	
	return 0;
}