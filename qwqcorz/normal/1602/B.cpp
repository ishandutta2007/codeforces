#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;

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
int a[N][N],tot[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) a[0][i]=read();
		for (int j=1;j<=n;j++)
		{
			for (int i=1;i<=n;i++) tot[a[j-1][i]]++;
			for (int i=1;i<=n;i++) a[j][i]=tot[a[j-1][i]];
			for (int i=1;i<=n;i++) tot[i]=0;
		}
		int Q=read();
		while (Q--)
		{
			int x=read(),k=read();
			print(a[min(k,n)][x]);
		}
	}
	
	return 0;
}