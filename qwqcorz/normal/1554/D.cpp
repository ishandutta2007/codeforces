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
	int T=read();
	while (T--)
	{
		int n=read();
		if (n<=26){for (int i=0;i<n;i++) putchar('a'+i);puts("");continue;}
		if (n%2==0) putchar('z'),n--;
		n=(n-3)/2;
		for (int i=0;i<n;i++) putchar('a'+(i&1));
		putchar('c');
		for (int i=0;i<n+2;i++) putchar('a'+(i&1));
		puts("");
	}
	
	return 0;
}