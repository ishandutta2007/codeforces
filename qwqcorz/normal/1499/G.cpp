#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
const int p=998244353;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int fa[N],col[N],h[N][2],Hash=0,pw[N],cnte=0,bel[N];
int find(int x)
{
	if (x==fa[x]) return x;
	int ret=find(fa[x]);
	if (fa[x]!=ret) col[x]^=col[fa[x]];
	return fa[x]=ret;
}
int getcol(int x)
{
	int rt=find(x);
	if (rt==x) return col[x];
	return col[rt]^col[x];
}
void merge(int x,int y)
{
	add(h[y][0],h[x][0]);
	add(h[y][1],h[x][1]);
	fa[x]=y;
	col[x]^=col[y];
}
void color(int x,int y)
{
	if (y) add(Hash,pw[x]);
	h[x][y]=pw[x];
	col[x]=y;
}
void connect(int x,int y)
{
	cnte++;
	if (!bel[x]) swap(x,y);
	if (!bel[x]&&!bel[y]) return bel[x]=bel[y]=cnte,h[cnte][0]=pw[cnte],void();
	if (!bel[y])
	{
		bel[y]=cnte;
		fa[cnte]=bel[x];
		col[cnte]=1;
		bel[x]=0;
		if (getcol(cnte)) add(Hash,pw[cnte]);
		add(h[find(cnte)][getcol(cnte)],pw[cnte]);
		return;
	}
	int tx=x,ty=y;
	x=bel[x],y=bel[y];
	int cx=getcol(x),cy=getcol(y);
	if (cx!=cy)
	{
		int fx=find(x);
		Hash=(1LL*Hash-h[fx][1]+h[fx][0]+p)%p;
		swap(h[fx][0],h[fx][1]),col[fx]^=1,cx^=1;
	}
	color(cnte,!cx);
	merge(find(x),cnte);
	if (find(x)!=find(y)) merge(find(y),cnte);
	bel[tx]=bel[ty]=0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	for (int i=1;i<N;i++) fa[i]=i;
	for (int i=pw[0]=1;i<N;i++) pw[i]=pw[i-1]*2%p;
	int n1=read(),n2=read(),m=read();(void)n2;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		connect(u,v+n1);
	}
	int q=read();
	while (q--)
	{
		int opt=read();
		if (opt==1)
		{
			int u=read(),v=read();
			connect(u,v+n1);
			print(Hash);
			fflush(stdout);
		}
		else
		{
			int tot=0;
			for (int i=1;i<=cnte;i++) tot+=getcol(i);
			print(tot,' ');
			for (int i=1;i<=cnte;i++) if (getcol(i)) print(i,' ');
			cout<<endl;
		}
	}
	
	return 0;
}
/*
2 2 4
1 1
1 2
2 1
2 2
*/