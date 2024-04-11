#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
const int K=11;

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
pair<int,int>tmp[K*K];
bool can[K][K][K][K],vis[N][K][K];
vector<pair<int,int> >e[N];
int n,m,k,ans=0,p[K];
void dfs(int now)
{
	if (now>k) return void(ans++);
	for (int i=0;i<now;i++)
	{
		p[now]=i;
		bool flag=1;
		for (int j=1;j<=now;j++)
		if (!can[j][p[j]][now][i])
		{
			flag=0;
			break;
		}
		if (!flag) continue;
		dfs(now+1);
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back(mk(w,v));
	}
	memset(can,1,sizeof(can));
	for (int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
	for (int i=1;i<=n;i++)
	for (int j=0;j<(int)e[i].size();j++)
	if (vis[e[i][j].se][e[i].size()][j]) can[e[i].size()][j][e[i].size()][j]=0;
	else vis[e[i][j].se][e[i].size()][j]=1;
	for (int t=1;t<=n;t++)
	{
		int cnt=0;
		for (int i=1;i<=k;i++)
		for (int j=0;j<k;j++)
		if (vis[t][i][j])
		tmp[cnt++]=mk(i,j);
		for (int i=0;i<cnt;i++)
		for (int j=0;j<cnt;j++)
		if (i!=j)
		can[tmp[i].fi][tmp[i].se][tmp[j].fi][tmp[j].se]=0;
	}
	dfs(1);
	print(ans);
	
	return 0;
}