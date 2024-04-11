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
int count(int x)
{
	int ret=0;
	while (x)
	{
		x&=x-1;
		ret++;
	}
	return ret;
}
struct edge
{
	int to,nxt;
}e[N];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int in[N],out[N],S[N],cntS=0,T[N],cntT=0,nS[N],nT[N],to[N];
int dfs(int now)
{
	if (to[now]) return to[now];
	if (out[now]==0) return 1<<nT[now];
	for (int i=head[now];i;i=e[i].nxt)
	to[now]|=dfs(e[i].to);
	return to[now];
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		out[u]++;
		in[v]++;
		add(u,v);
	}
	for (int i=1;i<=n;i++)
	if (in[i]==0)
	{
		S[++cntS]=i;
		nS[i]=cntS;
	}
	for (int i=1;i<=n;i++)
	if (out[i]==0)
	{
		T[++cntT]=i;
		nT[i]=cntT;
	}
	for (int i=1;i<=n;i++) to[i]=dfs(i);
	for (int i=1;i<(1<<cntS)-1;i++)
	{
		int cnt=0,mask=0;
		for (int j=1;j<=cntS;j++)
		if (i&(1<<(j-1)))
		{
			cnt++;
			mask|=to[S[j]];
		}
		if (cnt>=count(mask)) return puts("NO"),0;
	}
	puts("YES");

	return 0;
}