#include<bits/stdc++.h>
#define ll long long
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
void write(ll x)
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
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int siz0[N],siz1[N],fa[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll ans=0,sum0=0,sum1=0;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		fa[find(u)]=find(v);
		if (u==v) siz0[u]++;
		else
		{
			siz1[u]++;
			siz1[v]++;
		}
	}
	int x=1;
	for (int i=1;i<=n;i++)
	if (fa[i]!=i)
	x=i;
	for (int i=1;i<=n;i++)
	if (find(i)!=find(x)&&(siz1[i]||siz0[i]))
	return puts("0"),0;
	for (int i=1;i<=n;i++)
	{
		sum0+=siz0[i];
		sum1+=siz1[i];
		ans+=1LL*siz1[i]*(siz1[i]-1)/2;
	}
	ans+=1LL*sum0*(sum0-1)/2;
	ans+=1LL*sum0*sum1/2;
	print(ans);

	return 0;
}