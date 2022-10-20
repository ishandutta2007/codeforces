#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int p=1e9+7;

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
struct edge
{
	int to,nxt;
}e[N];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int dp[N][2];
bool col[N];
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
void dfs(int now)
{
	int mul=1,count=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		dfs(to);
		mul=mul*((dp[to][0]+dp[to][1])%p)%p;
	}
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		count=(count+mul*power((dp[to][0]+dp[to][1])%p,p-2)%p*dp[to][1]%p)%p;
	}
	if (col[now]==0)
	{
		dp[now][0]=mul;
		dp[now][1]=count;
	}
	else
	{
		dp[now][0]=0;
		dp[now][1]=mul;
	}
}

signed main()
{
	int n=read();
	for (int i=2;i<=n;i++)
	{
		int fa=read()+1;
		add(fa,i);
	}
	for (int i=1;i<=n;i++) col[i]=read();
	dfs(1);
//	for (int i=1;i<=n;i++) print(dp[i][0],' '),print(dp[i][1]);
	print(dp[1][1]);

	return 0;
}