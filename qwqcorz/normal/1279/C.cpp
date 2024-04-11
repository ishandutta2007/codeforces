#include<bits/stdc++.h>
#define int long long
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
int st[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),top=n,ans=0,tot=0;
		for (int i=1;i<=n;i++) st[top--]=read();
		top=n;
		for (int i=1;i<=m;i++)
		{
			int x=read();
			if (vis[x]) ans++,vis[x]=0,tot--;
			else
			{
				do vis[st[top]]=1,tot++;while (st[top--]!=x);
				ans+=tot--*2-1;
			}
		}
		print(ans);
		for (int i=1;i<=n;i++) vis[i]=0;
	}
	
	return 0;
}