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
	int n=read(),x=0,y=0,s=1;
	for (int i=1;i<=20;i++)
	{
		if (s==n||s+1==n) return puts("1"),0;
		int ns=s*2+1,nx=s,ny=s;
		if (y%2==1) ns++,nx++;
		if (x%2==0) ns++,ny++;
		s=ns,x=nx,y=ny;
	}
	puts("0");
	
	return 0;
}