#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=100111;

vector<int> g[maxn],l[maxn];
int n,m,f[maxn];
bool have[maxn];

int down[maxn],down_id[maxn],coef[maxn];
int up[maxn],up_id[maxn],up_mid[maxn];
void dfs(int x,int fa)
{
	f[x]=fa;
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=fa)
	{
		dfs(g[x][i],x);
		if(down[g[x][i]]==-1)continue;
		if(down[g[x][i]]+l[x][i]>down[x])
		{
			down[x]=down[g[x][i]]+l[x][i];
			down_id[x]=down_id[g[x][i]];
		}
		else if(down[g[x][i]]+l[x][i]==down[x])down_id[x]=x;
	}
}

void dfs2(int x)
{
	if(have[x])
	{
		if(up[x]<down[x])
		{
			coef[down_id[x]]++;
			coef[f[x]]--;
		}
		else if(up[x]>down[x])
		{
			coef[x]++;
			coef[up_id[x]]++;
			coef[up_mid[x]]--;
			coef[f[up_mid[x]]]--;
		}
	}
//	printf("x= %d down= %d %d up= %d %d %d\n",x,down[x],down_id[x],up[x],up_id[x],up_mid[x]);
	int cur_up,cur_id,cur_mid;
	cur_up=up[x];
	cur_id=up_id[x];
	cur_mid=up_mid[x];
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f[x])
	{
		if(down[g[x][i]]==-1)continue;
		if(cur_up!=-1)
		{
			up[g[x][i]]=cur_up+l[x][i];
			up_id[g[x][i]]=cur_id;
			up_mid[g[x][i]]=cur_mid;
		}
		if(down[g[x][i]]+l[x][i]>cur_up)
		{
			cur_up=down[g[x][i]]+l[x][i];
			cur_id=down_id[g[x][i]];
			cur_mid=x;
		}
		else if(down[g[x][i]]+l[x][i]==cur_up)cur_id=cur_mid=x;
	}
	cur_up=cur_id=cur_mid=-1;
	for(int i=(int)g[x].size()-1;i>=0;i--)if(g[x][i]!=f[x])
	{
		if(down[g[x][i]]==-1)continue;
		if(cur_up!=-1)
		{
			if(cur_up+l[x][i]>up[g[x][i]])
			{
				up[g[x][i]]=cur_up+l[x][i];
				up_id[g[x][i]]=cur_id;
				up_mid[g[x][i]]=cur_mid;
			}
			else if(cur_up+l[x][i]==up[g[x][i]])up_id[g[x][i]]=up_mid[g[x][i]]=x;
		}
		if(down[g[x][i]]+l[x][i]>cur_up)
		{
			cur_up=down[g[x][i]]+l[x][i];
			cur_id=down_id[g[x][i]];
			cur_mid=x;
		}
		else if(down[g[x][i]]+l[x][i]==cur_up)cur_id=cur_mid=x;
		dfs2(g[x][i]);
	}
}

void dfs3(int x)
{
	for(int i=0;i<(int)g[x].size();i++)if(g[x][i]!=f[x])
	{
		dfs3(g[x][i]);
		coef[x]+=coef[g[x][i]];
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		have[x]=1;
	}
	
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		g[u].pb(v);l[u].pb(w);
		g[v].pb(u);l[v].pb(w);
	}
	
	for(int x=1;x<=n;x++)
	{
		if(have[x])
		{
			up[x]=down[x]=0;
			up_id[x]=down_id[x]=up_mid[x]=x;
		}
		else up[x]=down[x]=up_id[x]=down_id[x]=up_mid[x]=-1;
	}
	dfs(1,0);
	dfs2(1);
	dfs3(1);
	
	int mx=0,cnt=0;
	for(int i=1;i<=n;i++)if(!have[i])mx=max(mx,coef[i]);
	for(int i=1;i<=n;i++)if(!have[i]&&coef[i]==mx)cnt++;
	printf("%d %d\n",mx,cnt);
	return 0;
}