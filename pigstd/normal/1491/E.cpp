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

const int M=2e5+10;
int n,vis[M],f[M],t[M],sz[M],ff[M];
vector<int>v,e[M];

void dfs1(int u,int fa)
{
	sz[u]=1;ff[u]=fa;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==fa||!vis[to])continue;
		dfs1(to,u);sz[u]+=sz[to];
	}
}

void dfs2(int u,int fa)
{
	v.pb(u);
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==fa||!vis[to])continue;
		dfs2(to,u);
	}
}

bool check(vector<int>p,int x)
{
	if (x<=4)return 1;
	for (int i=0;i<p.size();i++)
		vis[p[i]]=1;//,cout<<p[i]<<' ';
//	cout<<x<<endl;
	dfs1(p[0],0);
	for (int i=0;i<p.size();i++)
		if (sz[p[i]]==f[x-1]||sz[p[i]]==f[x-2])
		{
			v.clear();dfs2(p[i],ff[p[i]]);
			vector<int>pp;
			for (int i=0;i<v.size();i++)
				vis[v[i]]=0;
			for (int i=0;i<p.size();i++)
				if (vis[p[i]])
					vis[p[i]]=0,pp.pb(p[i]);
			int f1=x-1,f2=x-2;
			if (sz[p[i]]==f[x-2])swap(f1,f2);
			int _1=check(v,f1);
			int _2=check(pp,f2);
			return _1&_2;
		}
	return 0;
}

signed main()
{
	n=read();f[1]=f[2]=1;t[1]=1;
	for (int i=3;i<=30;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if (f[i]>n)break;
		t[f[i]]=i;
	}//cout<<f[30]<<endl;
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}if (t[n]==0)return puts("NO"),0;
	for (int i=1;i<=n;i++)v.pb(i);
	if (check(v,t[n]))YES
	else NO;
	return 0;
}