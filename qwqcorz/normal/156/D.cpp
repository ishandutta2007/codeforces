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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int power(int a,int b,int p)
{
	a%=p;
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int fa[N],siz[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read(),p=read(),k=n;
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for (int i=1;i<=m;i++)
	{
		int u=find(read()),v=find(read());
		if (u==v) continue;
		fa[u]=v;
		siz[v]+=siz[u];
		k--;
	}
	if (k==1) return print(1%p),0;
	int ans=power(n,k-2,p);
	for (int i=1;i<=n;i++) if (fa[i]==i) ans=1LL*ans*siz[i]%p;
	print(ans);
	
	return 0;
}