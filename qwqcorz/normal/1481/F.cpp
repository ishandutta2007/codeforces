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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int n,a,b,fa[N],deep[N],maxdeep;
void dfs(int now,int father)
{
	maxdeep=max(maxdeep,deep[now]=deep[father]+1);
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		dfs(to,now);
	}
}
vector<int>x[N],id[N][2];
int dp[N],from[N],num[N],tot[N],wid[N],wtot[N],w[N],cnt=0;
bool check()
{
	dp[0]=1;
	for (int i=1;i<=n;i++) num[deep[i]]++;
	for (int i=1;i<=maxdeep;i++) tot[num[i]]++,x[num[i]].push_back(i);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=tot[i];j+=j) cnt++,wid[cnt]=i,wtot[cnt]=j,tot[i]-=j;
		if (tot[i]) cnt++,wid[cnt]=i,wtot[cnt]=tot[i];
	}
	for (int i=1;i<=cnt;i++) w[i]=wid[i]*wtot[i];
	for (int i=1;i<=cnt;i++)
	for (int j=a;j>=w[i];j--)
	if (dp[j-w[i]]&&!dp[j])
	dp[j]=1,from[j]=i;
	return dp[a];
}
bool ans[N],vis[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),a=read(),b=n-a;
	for (int i=2;i<=n;i++) add_edge(fa[i]=read(),i);
	dfs(1,0);
	if (check())
	{
		print(maxdeep);
		for (int i=a;i;i=i-w[from[i]])
		for (int j=1;j<=wtot[from[i]];j++)
		{
			vis[x[wid[from[i]]].back()]=1;
			x[wid[from[i]]].pop_back();
		}
		for (int i=1;i<=n;i++) ans[i]=!vis[deep[i]];
	}
	else
	{
		print(maxdeep+1);
		for (int i=1;i<=n;i++) id[deep[i]][!!head[i]].push_back(i);
		int x=a,y=b;
		for (int i=1;i<=maxdeep;i++)
		{
			if ((int)id[i][1].size()<=x)
			{
				for (int j:id[i][1]) ans[j]=0;
				x-=id[i][1].size();
				while (!id[i][0].empty()&&x)
				{
					x--;
					ans[id[i][0].back()]=0;
					id[i][0].pop_back();
				}
			}
			else
			{
				for (int j:id[i][1]) ans[j]=1;
				y-=id[i][1].size();
				while (!id[i][0].empty()&&y)
				{
					y--;
					ans[id[i][0].back()]=1;
					id[i][0].pop_back();
				}
			}
			while (!id[i][0].empty()&&x)
			{
				x--;
				ans[id[i][0].back()]=0;
				id[i][0].pop_back();
			}
			while (!id[i][0].empty()&&y)
			{
				y--;
				ans[id[i][0].back()]=1;
				id[i][0].pop_back();
			}
		}
	}
	for (int i=1;i<=n;i++) putchar('a'+ans[i]);
	
	return 0;
}