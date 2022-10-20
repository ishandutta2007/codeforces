#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
int cnt=0,a[N],b[N];
int fr[N],to[N],cnte=0;
void add(int u,int v)
{
	fr[++cnte]=u;
	to[cnte]=v;
}

signed main()
{
	int n=read();
	if (n&1)
	{
		puts("YES");
		int s=++cnt;
		for (int i=1;i<n;i++) a[i]=++cnt,b[i]=++cnt;
		for (int i=1;i<n;i+=2) add(a[i],a[i+1]);
		for (int i=1;i<n;i++) add(s,b[i]);
		for (int i=1;i<n;i++)
		for (int j=1;j<n;j++) add(a[i],b[j]);
		print(cnt*2,' ');
		print(cnte*2+1);
		print(s,' ');
		print(s+cnt);
		for (int i=1;i<=cnte;i++)
		{
			print(fr[i],' ');
			print(to[i]);
			print(fr[i]+cnt,' ');
			print(to[i]+cnt);
		}
	}
	else puts("NO");

	return 0;
}