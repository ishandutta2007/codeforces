#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
struct edge
{
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int mu[N];
void ysgs(int n)
{
	for (int i=mu[1]=1;i<=n;i++)
	for (int j=i+i;j<=n;j+=i) mu[j]-=mu[i];
}
int f[N],g[N],siz[N];
bool dfs(int now,int father,int k)
{
	siz[now]=!!father;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		if (!dfs(to,now,k)) return 0;
		siz[now]++;
	}
	if (siz[now]%k==0) return siz[father]--,1;
	if (!father) return 0;
	if (siz[now]%k!=1) return 0;
	return 1;
}
void clear(int n)
{
	cnte=0;
	for (int i=1;i<=n;i++) head[i]=f[i]=g[i]=siz[i]=0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ysgs(1e5);
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add_edge(u,v);
			add_edge(v,u);
		}
		for (int i=2;i<n;i++) g[i]=(n-1)%i==0&&dfs(1,0,i);
		for (int i=2;i<=n;i++)
		for (int j=i;j<=n;j+=i)
		f[i]=(f[i]+mu[j/i]*g[j]+p)%p;
		f[1]=power(2,n-1);
		for (int i=2;i<n;i++) f[1]-=f[i];
		f[1]=(f[1]+p)%p;
		for (int i=1;i<=n;i++) print(f[i]," \n"[i==n]);
		clear(n);
	}
	
	return 0;
}