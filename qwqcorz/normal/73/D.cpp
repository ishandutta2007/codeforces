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
int fa[N],siz[N],a[N],cnt=0;
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

signed main(int Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++) siz[i]=1;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		int x=find(u),y=find(v);
		if (x!=y)
		{
			fa[x]=y;
			siz[y]+=siz[x];
		}
	}
	for (int i=1;i<=n;i++)
	if (find(i)==i)
	a[++cnt]=min(siz[i],k);
	if (k==1) print(max(cnt-2,0));
	else
	{
		int one=0,sum=0;
		for (int i=1;i<=cnt;i++)
		if (a[i]==1) one++;
		else sum+=a[i]-2;
		one=max(one-2,0);
		one=max(one-sum,0);
		print((one+1)/2);
	}

	return 0;
}