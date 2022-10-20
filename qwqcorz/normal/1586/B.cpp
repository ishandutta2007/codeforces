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
bool vis[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),pos=0;
		for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=1;i<=m;i++)
		{
			int u=read(),x=read(),v=read();
			vis[x]=1;
		}
		for (int i=1;i<=n;i++) if (!vis[i]) pos=i;
		for (int i=1;i<=n;i++) if (i!=pos) print(i,' '),print(pos);
	}
	
	return 0;
}