#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
int a[N],fa[N],siz[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int t[N];
int w[N],v[N],cnt=0;
int f[N];
bool check(int x)
{
	while (x)
	{
		if (x%10!=4&&x%10!=7) return 0;
		x/=10;
	}
	return 1;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) siz[i]=1,fa[i]=i;
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
	if (fa[i]==i)
	t[siz[i]]++;
	for (int i=1;i<=n;i++)
	if (t[i])
	{
		for (int j=1;j<=t[i];j*=2)
		{
			w[++cnt]=j*i;
			v[cnt]=j;
			t[i]-=j;
		}
		if (t[i])
		{
			w[++cnt]=t[i]*i;
			v[cnt]=t[i];
		}
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for (int i=1,sum=0;i<=cnt;sum+=w[i++])
	for (int j=sum;j>=0;j--)
	f[j+w[i]]=min(f[j+w[i]],f[j]+v[i]);
	int ans=1919810;
	for (int i=1;i<=n;i++)
	if (check(i))
	ans=min(ans,f[i]);
	if (ans==1919810) puts("-1");
				 else print(ans-1);

	return 0;
}