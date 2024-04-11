#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1e3;

int n,m,head[N],cnt=0,ans[N],size[N],fa[N];
struct edge
{
	int to,next;
}e[N];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(int n)
{
    if (n<0)
    {
        putchar('-');
        n=abs(n);
    }
    if (n<10)
    {
        putchar(n+'0');
        return;
    }
    write(n/10);
    putchar(n%10+'0');
}
void dfs(int now)
{
	int Max=0;
	size[now]=1;
	ans[now]=now;
	for (int i=head[now];i;i=e[i].next)
	{
		int to=e[i].to;
		dfs(to);
		size[now]+=size[to];
		if (size[Max]<size[to]) Max=to;
	}
	if (size[Max]*2>size[now])
	{
		int tmp=ans[Max];
		while ((size[now]-size[tmp])*2>size[now]) tmp=fa[tmp];
		ans[now]=tmp;
	}
}

int main()
{
	n=read();
	m=read();
	for (int i=2;i<=n;i++)
	{
		int x=read();
		add(x,i);
		fa[i]=x;
	}
	dfs(1);
	for (int i=1;i<=m;i++)
	{
		int x=read();
		write(ans[x]);
		putchar('\n');
	}

	return 0;
}