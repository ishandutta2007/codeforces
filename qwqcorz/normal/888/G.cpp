#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const ll inf=1ll<<60;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register ll x)
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
inline void print(const register ll x,const register char c='\n')
{
	write(x);
	putchar(c);
}
ll ans=0;
int a[N],cnt=0;
struct node
{
	int son[2];
	int tot;
}t[N*30];
void add(int now,int i,int v)
{
	t[now].tot++;
	if (i<0) return;
	int x=(v>>i)&1;
	if (!t[now].son[x]) t[now].son[x]=++cnt;
	add(t[now].son[x],i-1,v);
}
ll dfs(int w1,int w2,int i)
{
	if (i<0) return 0;
	ll ret=inf;
	if (t[w1].son[0]&&t[w2].son[0]) ret=min(ret,dfs(t[w1].son[0],t[w2].son[0],i-1));
	if (t[w1].son[1]&&t[w2].son[1]) ret=min(ret,dfs(t[w1].son[1],t[w2].son[1],i-1));
	if (ret<inf) return ret;
	if (t[w1].son[0]&&t[w2].son[1]) return dfs(t[w1].son[0],t[w2].son[1],i-1)+(1<<i);
	if (t[w1].son[1]&&t[w2].son[0]) return dfs(t[w1].son[1],t[w2].son[0],i-1)+(1<<i);
}
void solve(int now,int i)
{
	if (t[now].son[0]&&t[now].son[1]) ans+=dfs(t[now].son[0],t[now].son[1],i-1)+(1<<i);
	if (t[now].son[0]) solve(t[now].son[0],i-1);
	if (t[now].son[1]) solve(t[now].son[1],i-1);
}

int main()
{
	memset(t,0,sizeof(t));
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) add(0,30,a[i]);
	solve(0,30);
	print(ans);

	return 0;
}