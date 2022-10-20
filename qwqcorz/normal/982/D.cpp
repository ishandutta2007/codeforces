#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
bool f[N];
int p[N],a[N],fa[N],siz[N];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int u=find(x),v=find(y);
	fa[u]=v;
	siz[v]+=siz[u];
}

int main()
{
	memset(f,0,sizeof(f));
	int n=read();
	for (int i=1;i<=n;i++) p[i]=fa[i]=i,siz[i]=1;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(p+1,p+1+n,cmp);
	int tot=0,cnt=0,L=1,Max=0,ans;//totcntLMaxans 
	for (int i=1;i<=n;i++)
	{
		int now=p[i];
		f[now]=1;
		if (!f[now-1]&&!f[now+1])
		{
			tot++;
			if (L==1) cnt++;
		}
		else if (f[now-1]&&f[now+1])
		{
			tot--;
			merge(now-1,now);
			merge(now+1,now);
			if (siz[now]>L)
			{
				L=siz[now];
				cnt=1;
			}
			else if (siz[now]==L) cnt++;
		}
		else
		{
			if (f[now-1]) merge(now-1,now);
			if (f[now+1]) merge(now+1,now);
			if (siz[now]>L)
			{
				L=siz[now];
				cnt=1;
			}
			else if (siz[now]==L) cnt++;
		}
		if (tot==cnt)
		if (tot>Max)
		{
			Max=tot;
			ans=a[now]+1;
		}
	}
	print(ans);

	return 0;
}