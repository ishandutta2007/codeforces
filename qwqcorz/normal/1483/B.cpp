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
int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}
int nxt[N],a[N],q[N*5],out[N];
bool vis[N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),h=1,t=0,k=0;
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) nxt[i]=i%n+1;
		for (int i=1;i<=n;i++) if (gcd(a[i],a[nxt[i]])==1) q[++t]=i;
		while (h<=t)
		{
			int x=q[h++];
			if (vis[x]) continue;
			vis[nxt[x]]=1;
			out[++k]=nxt[x];
			nxt[x]=nxt[nxt[x]];
			if (gcd(a[x],a[nxt[x]])==1) q[++t]=x;
		}
		print(k,' ');
		for (int i=1;i<=k;i++) print(out[i],' ');
		puts("");
		for (int i=1;i<=n;i++) vis[i]=0;
	}

	return 0;
}