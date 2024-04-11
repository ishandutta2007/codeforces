//AFO countdown:???
#include<bits/stdc++.h>
//#define int long long
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

const int M=5e5+10;
const int inf=1e9;
const int N=(1<<22)+10;
int n,a[M],b[M],de[M],sz[M],son[M],cnt[N],ans[M];
vector<int>e[M];
vector<pair<int,int> >v;
string s;

void dfs1(int u)
{
	sz[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		dfs1(to),sz[u]+=sz[to];
		if (sz[to]>sz[son[u]])
			son[u]=to;
	}
}

void dfs3(int u,int x,int y)
{
	x^=a[u],v.pb(mp(x,y));
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		dfs3(to,x,y+1);
	}
}

void dfs4(int u,int x,int y)
{
	x^=a[u];cnt[x^y]=-inf;
	for (int i=0;i<e[u].size();i++)
		dfs4(e[u][i],x,y);
}

void dfs2(int u)
{
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==son[u])continue;
		dfs2(to);ans[u]=max(ans[u],ans[to]);
		dfs4(to,0,b[to]);
	}
	if (!son[u])
	{
		de[u]=0;cnt[0]=0,b[u]=a[u];
		return;
	}
	dfs2(son[u]);b[u]=a[u]^b[son[u]];
	ans[u]=max(ans[u],ans[son[u]]);de[u]=de[son[u]]+1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==son[u])continue;v.clear();
		dfs3(to,0,1);
		for (int j=0;j<v.size();j++)
		{
			v[j].y-=de[u],v[j].x^=b[son[u]];
			ans[u]=max(ans[u],cnt[v[j].x]+v[j].y+2*de[u]);
			for (int k=0;k<22;k++)
				ans[u]=max(ans[u],cnt[v[j].x^(1<<k)]+v[j].y+2*de[u]);
		}
		for (int j=0;j<v.size();j++)
			cnt[v[j].x]=max(cnt[v[j].x],v[j].y);
	}
	ans[u]=max(ans[u],cnt[b[son[u]]]+de[u]);
	for (int i=0;i<22;i++)
		ans[u]=max(ans[u],cnt[b[son[u]]^(1<<i)]+de[u]);
	cnt[b[u]^a[u]]=max(-de[u],cnt[b[u]^a[u]]);
}

signed main()
{
	n=read();
	for (int i=2;i<=n;i++)
	{
		int x=read();cin>>s;
		a[i]=1<<(s[0]-'a');e[x].pb(i);
	}
	for (int i=0;i<N;i++)cnt[i]=-inf;
	dfs1(1);
	dfs2(1);
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}