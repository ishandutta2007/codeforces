#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N][N];
bool vis[N][N];
int ans[N][N],st[N][N],n,m;
int dfs(int x,int y,int step)
{
	//print(x,' '),print(y,':'),print(step);putchar(a[x][y]);
	if (x<1||x>n||y<1||y>m) return 0;
	if (~ans[x][y]) return ans[x][y];
	if (vis[x][y]) return ans[x][y]=step-st[x][y],-1;
	vis[x][y]=1,st[x][y]=step;
	int nx=x,ny=y;
	if (a[x][y]=='L') ny--;
	if (a[x][y]=='R') ny++;
	if (a[x][y]=='U') nx--;
	if (a[x][y]=='D') nx++;
	int get=dfs(nx,ny,step+1);
	if (~ans[x][y]) return ans[x][y];
	if (~get) return ans[x][y]=get+1;
		 else return ans[x][y]=ans[nx][ny],-1;
}
void GreenDay()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	ans[i][j]=-1,vis[i][j]=0;
	pair<int,pair<int,int>>mx;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (!vis[i][j]) dfs(i,j,0),mx=max(mx,make_pair(ans[i][j],make_pair(i,j)));
	//for (int i=1;i<=n;i++)
	//for (int j=1;j<=m;j++) print(ans[i][j],",\n"[j==m]);
	print(mx.second.first,' ');
	print(mx.second.second,' ');
	print(mx.first);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}