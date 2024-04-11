#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
int AskDis(int x)
{
	printf("d %d\n",x);
	fflush(stdout);
	return read();
}
int AskSon(int x)
{
	printf("s %d\n",x);
	fflush(stdout);
	return read();
}
vector<int>e[N];
int d,siz[N],deep[N],fa[N];
void dfs(int now,int father)
{
	deep[now]=deep[fa[now]=father]+1;
	siz[now]=deep[now]==d;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
		siz[now]+=siz[to];
	}
}

signed main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	d=AskDis(1)+1;
	dfs(1,0);
	int now=1;
	while (siz[now]>1)
	{
		while (deep[now]<d)
		{
			pair<int,int>mx(0,0);
			for (int to:e[now]) if (to!=fa[now]) mx=max(mx,make_pair(siz[to],to));
			now=mx.second;
		}
		int dis=AskDis(now)/2;
		for (int i=1;i<=dis;i++) now=fa[now];
		if (siz[now]>1) now=AskSon(now);
	}
	while (deep[now]<d) for (int to:e[now]) if (to!=fa[now]&&siz[to]){now=to;break;}
	printf("! %d\n",now);
	
	return 0;
}