//AFO countdown:14 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=510;
int n,m,a[M][M],ans[M][M],vis[M][M];
int F(int x,int y){return (x-1)*m+y;}
int Gx(int x){return (x-1)/m+1;}
int Gy(int x){return x%m==0?m:x%m;}
vector<int>e[M*M],v;
int fx[]={-1,0,1,0};
int fy[]={0,1,0,-1};

void dfs(int u)
{
	vis[Gx(u)][Gy(u)]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (vis[Gx(to)][Gy(to)])continue;
		ans[Gx(to)][Gy(to)]=ans[Gx(u)][Gy(u)]^1,dfs(to);
	}
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		string s;cin>>s;
		for (int j=0;j<m;j++)
			a[i][j+1]=s[j]=='.'?0:1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (!a[i][j])continue;
			v.clear();
			for (int k=0;k<4;k++)
			{
				int tx=i+fx[k],ty=j+fy[k];
				if (!a[tx][ty])
					v.pb(F(tx,ty));
			}
			if (v.size()%2==1)return puts("NO"),0;
			for (int i=0;i<v.size();i+=2)
				e[v[i]].pb(v[i+1]),e[v[i+1]].pb(v[i]);//,cout<<v[i]<<' '<<v[i+1]<<endl; 
		}
	puts("YES");
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!vis[i][j]&&!a[i][j])dfs(F(i,j));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!a[i][j])ans[i][j]=ans[i][j]?4:1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j])
				for (int k=0;k<4;k++)
				{
					int tx=i+fx[k],ty=j+fy[k];
					if (!a[tx][ty])ans[i][j]+=ans[tx][ty];
				}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<ans[i][j]<<' ';
		puts("");
	}
	return 0;
}