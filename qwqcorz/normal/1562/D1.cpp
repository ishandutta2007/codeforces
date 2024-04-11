#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
char s[N];
int a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),q=read();
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='+'?1:-1)*(i%2?1:-1);
		while (q--)
		{
			int l=read(),r=read();
			if (a[r]-a[l-1]==0) puts("0");
			else print((r-l)%2?2:1);
		}
	}
	
	return 0;
}