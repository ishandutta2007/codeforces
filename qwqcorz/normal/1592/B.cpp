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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],b[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int T=read();
	while (T--)
	{
		int n=read(),x=read();
		for (int i=1;i<=n;i++) b[i]=a[i]=read();
		sort(b+1,b+1+n);
		bool flag=1;
		for (int i=n-x+1;i<=x;i++) if (a[i]!=b[i]) flag=0;
		puts(flag?"YES":"NO");
	}
	
	return 0;
}