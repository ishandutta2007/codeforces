#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=6e5+5;

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
struct edge
{
	int to,nxt;
}e[N*17];
int head[N],cnte=0,siz[N];
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
	siz[v]++;
}
char s[N][4],tmp[4],myh[4];
int n,m,k,ha[M],zyk[20];
int Hash(char *a)
{
	int ret=0;
	for (int i=0;i<k;i++)
	{
		if (a[i]=='_') a[i]='z'+1;
		ret=ret*27+a[i]-'a';
	}
	return ret;
}
int q[N],h=1,t=0;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		ha[Hash(s[i])]=i;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%s",tmp);
		int cnt=0;
		for (int S=0;S<(1<<k);S++)
		{
			for (int j=0;j<k;j++)
			if ((S>>j)&1) myh[j]=tmp[j];
					 else myh[j]='_';
			int hhh=Hash(myh);
			if (ha[hhh]) zyk[++cnt]=ha[hhh];
		}
		int x=read(),flag=0;
		for (int j=1;j<=cnt;j++) if (zyk[j]==x) flag=1;
		if (flag)
		{
			for (int j=1;j<=cnt;j++) if (zyk[j]!=x) add_edge(x,zyk[j]);
		}
		else
		{
			puts("NO");
			return 0;
		}
	}
	for (int i=1;i<=n;i++) if (!siz[i]) q[++t]=i;
	while (h<=t)
	{
		int now=q[h++];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (!--siz[to]) q[++t]=to;
		}
	}
	if (t<n) puts("NO");
	else
	{
		puts("YES");
		for (int i=1;i<=n;i++) print(q[i],' ');
		puts("");
	}
	
	return 0;
}