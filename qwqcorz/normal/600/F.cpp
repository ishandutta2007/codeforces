#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const int M=1e5+5;

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
int col[M],e[N][N],id[N][N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read(),num=read(),ans=0;
	for (int k=1;k<=num;k++)
	{
		int x=read(),y=read()+n,p=0,q=0;
		id[x][y]=k;
		for (int i=1;i<=m;i++)
		if (!e[x][i])
		{
			p=i;
			break;
		}
		for (int i=1;i<=n;i++)
		if (!e[y][i])
		{
			q=i;
			break;
		}
		ans=max(ans,max(p,q));
		e[x][p]=y;
		e[y][q]=x;
		if (p==q) continue;
		for (int now=y,c=q;now;now=e[now][c],c^=p^q) swap(e[now][p],e[now][q]);
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=ans;j++)
	if (e[i][j])
	col[id[i][e[i][j]]]=j;
	print(ans);
	for (int i=1;i<=num;i++) print(col[i],' ');

	return 0;
}