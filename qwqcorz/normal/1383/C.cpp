#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=20;

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
inline void up(int &x,int y){if (x<y) x=y;}
char a[N],b[N];
int e[M],dp[1<<M],fa[M];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void add_edge(int u,int v){e[v]|=1<<u,fa[find(u)]=find(v);}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int T=read();
	while (T--)
	{
		memset(e,0,sizeof(e));
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		int n=read(),tot=0,ans=0;
		scanf("%s%s",a+1,b+1);
		for (int i=0;i<M;i++) fa[i]=i;
		for (int i=1;i<=n;i++) if (a[i]!=b[i]) add_edge(a[i]-'a',b[i]-'a');
		for (int i=0;i<M;i++) tot+=fa[i]==i;
		for (int i=0;i<(1<<M);i++)
		if (dp[i]>=0)
		{
			ans=max(ans,dp[i]);
			for (int j=0;j<M;j++)
			if ((~i>>j&1)&&!(e[j]&i))
			up(dp[i|1<<j],dp[i]+1);
		}
		print(M-ans+M-tot);
	}
	
	return 0;
}