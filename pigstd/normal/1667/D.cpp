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

const int M=2e5+10;
int n,u[M],v[M],c[M],deg[M],in[M],F=1;
vector<int>e2[2][M],e3[M];
vector<pii>e[M];

void dfs(int u,int fa,int tmp=0)
{
	int cnt=0;
	for (auto v:e[u])
	{
		if (v.x==fa)continue;
		dfs(v.x,u,v.y);cnt+=c[v.y];
	}
	if (tmp!=0)
	{
		if (deg[u]&1)
		{
			if (cnt==deg[u]/2)c[tmp]=1;
			else if (cnt!=deg[u]/2+1)F=0; 
		}
		else
		{
			if (cnt==deg[u]/2-1)c[tmp]=1;
			else if (cnt!=deg[u]/2)F=0;
		}
	}
	else if (cnt!=(deg[u]+1)/2)F=0;
}

void Assert(int x){if (!x)while(1);}

void solve()
{
	n=read();F=1;
	for (int i=1;i<=n;i++)deg[i]=in[i]=c[i]=0,e[i].clear(),e2[0][i].clear(),e2[1][i].clear(),e3[i].clear();
	for (int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read();
		e[u[i]].pb(mp(v[i],i)),e[v[i]].pb(mp(u[i],i));
		deg[u[i]]++,deg[v[i]]++;
	}
	dfs(1,0);
	if (!F)return puts("NO"),void();
	YES
	for (int i=1;i<n;i++)
		e2[c[i]][u[i]].pb(i),e2[c[i]][v[i]].pb(i);
	for (int i=1;i<=n;i++)
		if (deg[i]&1)
		{
			Assert(e2[1][i].size()==e2[0][i].size()+1);
			for (int j=0;j<deg[i]/2;j++)
				e3[e2[1][i][j]].pb(e2[0][i][j]),in[e2[0][i][j]]++,
				e3[e2[0][i][j]].pb(e2[1][i][j+1]),in[e2[1][i][j+1]]++;
		}
		else
		{
			Assert(e2[1][i].size()==e2[0][i].size());
			for (int j=0;j+1<deg[i]/2;j++)
				e3[e2[0][i][j]].pb(e2[1][i][j]),in[e2[1][i][j]]++,
				e3[e2[1][i][j]].pb(e2[0][i][j+1]),in[e2[0][i][j+1]]++;
			e3[e2[0][i][deg[i]/2-1]].pb(e2[1][i][deg[i]/2-1]),in[e2[1][i][deg[i]/2-1]]++;
		}
	queue<int>q;
	for (int i=1;i<n;i++)
		if (!in[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		cout<<u[x]<<' '<<v[x]<<'\n';
		for (auto v:e3[x])
		{
			in[v]--;
			if (!in[v])q.push(v);
		}
	}
}

signed main()
{
	WT solve();
	return 0;
}