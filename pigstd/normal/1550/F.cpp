#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define ins insert
#define era erase
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

const int inf=1e18;
const int M=2e5+10;
int n,q,st,d,f[M],a[M],p[M];
vector<pair<int,int> >e[M];
vector<int>v[M];
set<pair<int,int> >s;

void dfs(int u,int fa,int w)
{
	p[u]=w;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,ww=e[u][i].y;
		if (to==fa)continue;dfs(to,u,max(ww,w));
	}
}

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

signed main()
{
	n=read(),q=read(),st=read(),d=read();
	for (int i=1;i<=n;i++)a[i]=read(),f[i]=i,s.ins(mp(a[i],i));
	while(1)
	{
		int ff=1;
		for (int i=1;i<=n;i++)v[i].clear();
		for (int i=1;i<=n;i++)
		{
			if (find(i)!=find(1))ff=0;
			v[find(i)].pb(i);
		}if (ff)break;
		for (int i=1;i<=n;i++)
		{
			if (v[i].size()==0)continue;
			int minn=inf,x=-1,y=-1;
			for (int j=0;j<v[i].size();j++)
				s.era(mp(a[v[i][j]],v[i][j]));
			for (int j=0;j<v[i].size();j++)
			{
				set<pair<int,int> >::iterator t=s.lower_bound(mp(a[v[i][j]]+d,0));
				if (t!=s.end())
				{
					int dis=abs(d-abs(a[v[i][j]]-(*t).x));
					if (dis<minn)minn=dis,x=v[i][j],y=(*t).y;
				}
				if (t!=s.begin())
				{
					t--;
					int dis=abs(d-abs(a[v[i][j]]-(*t).x));
					if (dis<minn)minn=dis,x=v[i][j],y=(*t).y;
				}
				t=s.lower_bound(mp(a[v[i][j]]-d,0));
				if (t!=s.end())
				{
					int dis=abs(d-abs(a[v[i][j]]-(*t).x));
					if (dis<minn)minn=dis,x=v[i][j],y=(*t).y;
				}
				if (t!=s.begin())
				{
					t--;
					int dis=abs(d-abs(a[v[i][j]]-(*t).x));
					if (dis<minn)minn=dis,x=v[i][j],y=(*t).y;
				}
			}
			for (int j=0;j<v[i].size();j++)
				s.ins(mp(a[v[i][j]],v[i][j]));
			if (find(x)!=find(y))
				e[x].pb(mp(y,minn)),e[y].pb(mp(x,minn)),
				f[find(x)]=find(y);//,cout<<x<<' '<<y<<' '<<minn<<endl;
		}
	}
	dfs(st,0,0);
//	for (int i=1;i<=n;i++)cout<<p[i]<<' ';puts("");
	while(q--)
	{
		int x=read(),k=read();
		if (p[x]<=k)puts("Yes");
		else puts("No");
	}
	return 0;
}