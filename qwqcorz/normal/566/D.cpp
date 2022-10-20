#include<bits/stdc++.h>
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
int fa[N],nxt[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	int n=read(),q=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++) nxt[i]=i+1;
	for (int i=1;i<=q;i++)
	{
		int op=read(),l=read(),r=read();
		if (l>r) swap(l,r);
		if (op==1) fa[find(r)]=find(l);
		if (op==2)
		for (int to,j=nxt[l];j<=r;j=to)
		{
			fa[find(j)]=find(j-1);
			to=nxt[j];
			nxt[j]=nxt[r];
		}
		if (op==3) puts(find(l)==find(r)?"YES":"NO");
	}

	return 0;
}