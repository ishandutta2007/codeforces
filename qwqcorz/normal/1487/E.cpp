#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N*3];
int head[4][N],cnt;
void add(int x,int y,int z)
{
	e[++cnt].to=z;
	e[cnt].nxt=head[x][y];
	head[x][y]=cnt;
}
int n[4],dp[4][N],a[4][N],ans=1e9;
multiset<int>s;

signed main()
{
	for (int i=0;i<4;i++) n[i]=read();
	for (int i=0;i<4;i++)
	for (int j=1;j<=n[i];j++) a[i][j]=read();
	for (int i=1;i<4;i++)
	{
		int m=read();
		for (int j=1;j<=m;j++)
		{
			int x=read(),y=read();//print(x,',');print(y);
			add(i,y,x);
		}
	}
	for (int i=1;i<=n[0];i++) dp[0][i]=a[0][i];
	for (int i=1;i<4;i++/*,puts("")*/)
	{
		s.clear();
		for (int j=1;j<=n[i-1];j++) s.insert(dp[i-1][j]);
		for (int j=1;j<=n[i];j++)
		{
			for (int t=head[i][j];t;t=e[t].nxt)
			{
				int to=e[t].to;//print(to,' ');
				s.erase(s.find(dp[i-1][to]));
			}
			if (s.empty()) dp[i][j]=ans;
					  else dp[i][j]=*s.begin()+a[i][j];//print(dp[i][j],',');
			for (int t=head[i][j];t;t=e[t].nxt)
			{
				int to=e[t].to;
				s.insert(dp[i-1][to]);
			}
		}
	}
	for (int i=1;i<=n[3];i++) ans=min(ans,dp[3][i]);
	if (ans>=(int)1e9) puts("-1");
				  else print(ans);

	return 0;
}