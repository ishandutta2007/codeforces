#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=110;
int f[M][M][M],dis[M][M],n,vis[M],fa[M],sz[M];
vector<pii>ans;
vector<int>e[M]; 
string s;

void dfs(int u,int fa,int s)
{
	for (auto v:e[u])
		if (v!=fa)
			dis[s][v]=dis[s][u]+1,dfs(v,u,s);
}

int check()
{
	for (int i=1;i<=n;i++)e[i].clear();
	for (auto x:ans)e[x.x].pb(x.y),e[x.y].pb(x.x);
	for (int i=1;i<=n;i++)dfs(i,0,i);
	for (int i=1;i<=n;i++)for (int j=i+1;j<=n;j++)for (int k=1;k<=n;k++)
		if (f[i][j][k]!=(dis[i][k]==dis[j][k]))return 0;
	return 1;
}

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void solve()
{
	n=read();ans.clear();
	for (int i=1;i<=n;i++)vis[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			cin>>s;
			for (int k=0;k<n;k++)f[i][j][k+1]=f[j][i][k+1]=s[k]-'0';
		}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)fa[j]=j;
		for (int j=1;j<=n;j++)for (int k=j+1;k<=n;k++)
			if (f[j][k][i])fa[find(j)]=find(k);
		for (int j=1;j<=n;j++)for (int k=j+1;k<=n;k++)
			if ((find(j)==find(k))!=f[j][k][i])return puts("No"),void();
	}
	for (int i=1;i<=n-2;i++)
	{
		int flag=0;
		for (int j=1;j<=n;j++)
		{
			if (vis[j])continue;
			int p=-1;
			for (int k=1;k<=n;k++)fa[k]=k,sz[k]=1;
			for (int w1=1;w1<=n;w1++)for (int w2=w1+1;w2<=n;w2++)
				if (!vis[w1]&&!vis[w2]&&f[w1][w2][j])
				{
					int x=find(w1),y=find(w2);
					fa[x]=y,sz[y]+=sz[x],sz[x]=0;
				}
			for (int k=1;k<=n;k++)
			{
				if (vis[k]||k==j||sz[find(k)]!=1)continue;
				int t=1;
				for (int w1=1;w1<=n&&t;w1++)
				{
					if (vis[w1]||w1==j)continue;
					for (int w2=w1+1;w2<=n&&t;w2++)
						if (!vis[w2]&&w2!=j&&f[w1][w2][k]!=f[w1][w2][j])t=0;
				}
				if (!t)continue;
				t=0;
				for (int w1=1;w1<=n;w1++)
				{
					if (vis[w1]||w1==j)continue;
					if (f[w1][j][k])t=1;
				}
				if (t){p=k;break;}
			}
			if (p!=-1){ans.pb(mp(j,p)),vis[j]=1,flag=1;break;}
		}
		if (!flag)return puts("No"),void();
	}
	int x=-1,y=-1;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			if (x==-1)x=i;
			else y=i;
		}
	ans.pb(mp(x,y));
	if (!check())puts("No");
	else
	{
		puts("Yes");
		for (auto x:ans)cout<<x.x<<' '<<x.y<<'\n';
	}
}

signed main()
{
//	freopen("1.out","r",stdin);
	WT solve();
	return 0;
}
/*

1
7
0000000 0000000 0010000 0100010 0100101 0000000 
1000000 0000000 0000000 0000000 0000100 
0000000 0000000 0000000 0100010 
1000000 1000000 0000000 
1111000 0000000 
0000000 


7
1 2
1 3
3 4
2 5
2 6
5 7
*/