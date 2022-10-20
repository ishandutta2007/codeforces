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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
bool edge[N],odd[N];
int siz[N],fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		siz[u]++;
		siz[v]++;
		fa[find(u)]=find(v);
		edge[find(u)]=1;
	}
	for (int i=1;i<=n;i++) ans+=siz[i]&1;
	for (int i=1;i<=n;i++) if (siz[i]&1) odd[find(i)]=1;
	ans/=2;
	bool ck=0;
	int tot=0;
	for (int i=1;i<=n;i++)
	if (find(i)==i)
	{
		if (edge[i]&&!odd[i]) tot++;
		if (edge[i]&&odd[i]) ck=1;
	}
	if (tot) tot+=siz[1]==0;
		else ans+=siz[1]==0;
	ans+=tot-(tot==1&&!ck);
	print(ans-(m==0));

	return 0;
}
///2+-(=1)+[1=0]-[m=0]