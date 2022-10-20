#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
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
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
int fa[N][2],siz[N][2];
int find(int x,int y)
{
	return fa[x][y]==x?x:fa[x][y]=find(fa[x][y],y);
}
void merge(int u,int v,int w)
{
	int x=find(u,w),y=find(v,w);
	fa[x][w]=y;
	siz[y][w]+=siz[x][w];
}

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		fa[i][0]=fa[i][1]=i;
		siz[i][0]=siz[i][1]=1;
	}
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		merge(u,v,w);
	}
//	for (int i=1;i<=n;i++) print(siz[find(i,0)][0],' '),print(siz[find(i,1)][1]);
	for (int i=1;i<=n;i++) ans+=siz[find(i,0)][0]*siz[find(i,1)][1];
	print(ans-n);
}