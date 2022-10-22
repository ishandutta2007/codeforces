#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int n,m,k;

vector<pii>e[N];

vector<int>v[101][101];

int ban[10][10][10][10],vis[N];

int c[10],ans;

void check()
{
	int ok=1;
	for(int i=1;i<=k&&ok;i++)
		for(int j=i+1;j<=k&&ok;j++)
		{
			if(ban[i][j][c[i]][c[j]])
				ok=0;
		}
	ans+=ok;
}

void dfs(int x)
{
	if(x==k+1)
	{
		check();
		return;
	}
	for(int i=1;i<=x;i++)
		c[x]=i,dfs(x+1);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(mp(w,v));
	}
	for(int i=1;i<=n;i++)
		sort(e[i].begin(),e[i].end());
	for(int i=1;i<=n;i++)
		if(e[i].size()==0)
		{
			puts("0");
			return 0;
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<e[i].size();j++)
			v[e[i].size()][j+1].push_back(e[i][j].sd);
	if(k==1)
	{
		for(int i=0;i<v[1][1].size();i++)
			vis[v[1][1][i]]++;
		int ok=1;
		for(int i=1;i<=n;i++)
			if(vis[i]>=2)
				ok=0;
		printf("%d\n",ok);
		return 0;
	}
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
		{
			for(int t=1;t<=i;t++)
				for(int s=1;s<=j;s++)
				{
					for(int w=0;w<v[i][t].size();w++)
					{
						vis[v[i][t][w]]++;
						if(vis[v[i][t][w]]>=2)
							ban[i][j][t][s]=1;
					}
					for(int w=0;w<v[j][s].size();w++)
					{
						vis[v[j][s][w]]++;
						if(vis[v[j][s][w]]>=2)
							ban[i][j][t][s]=1;
					}
					for(int w=0;w<v[i][t].size();w++)
						vis[v[i][t][w]]--;
					for(int w=0;w<v[j][s].size();w++)
						vis[v[j][s][w]]--;
				}
		}
	dfs(1);
	printf("%d\n",ans);
}