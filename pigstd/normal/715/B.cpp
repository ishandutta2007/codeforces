//AFO countdown:13 Days
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

const int inf=1e18;
const int M=10010;
int n,m,u[M],v[M],w[M],a[M],b[M],cnt,dis[M],vis[M],L,s,t;
vector<pair<int,int> >e1[M],e2[M];

priority_queue<pair<int,int> >q;

void dij(int u)
{
	for (int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
	q.push(mp(0,u)),dis[u]=0;
	while(!q.empty())
	{
		int u=q.top().y,w=-q.top().x;q.pop();
		if (vis[u])continue;vis[u]=1;
		for (int j=0;j<e2[u].size();j++)
		{
			int to=e2[u][j].x,ww=e2[u][j].y+w;
			if (ww<dis[to])
				dis[to]=ww,q.push(mp(-ww,to));
		}
	}
}

int check(int x)
{
	for (int i=1;i<=n;i++)e2[i]=e1[i];
	for (int i=1;i<=x;i++)
		e2[a[i]].pb(mp(b[i],1)),e2[b[i]].pb(mp(a[i],1));
	dij(s);return dis[t];
}

int work(int p,int Mid)
{
	for (int i=1;i<=n;i++)e2[i]=e1[i];
	e2[a[p]].pb(mp(b[p],Mid)),e2[b[p]].pb(mp(a[p],Mid));
	dij(s);return dis[t];
}

signed main()
{
	n=read(),m=read(),L=read(),s=read()+1,t=read()+1;
	for (int i=1;i<=m;i++)
	{
		u[i]=read()+1,v[i]=read()+1,w[i]=read();
		if (w[i]!=0)e1[u[i]].pb(mp(v[i],w[i])),e1[v[i]].pb(mp(u[i],w[i]));
		else a[++cnt]=u[i],b[cnt]=v[i];
	}
	if (cnt==0)
	{
		if (check(0)==L)
		{
			puts("YES");
			for (int i=1;i<=m;i++)
				cout<<u[i]-1<<' '<<v[i]-1<<' '<<w[i]<<endl;
		}
		else puts("NO");return 0;
	}
//	cout<<check(0)<<' '<<check(cnt)<<endl; 
	if (check(0)<L||check(cnt)>L)return puts("NO"),0;
//	puts("???");
	int tl=1,tr=cnt,p=-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid)<=L)p=Mid,tr=Mid-1;
		else tl=Mid+1;
	}
	for (int i=1;i<p;i++)
		e1[a[i]].pb(mp(b[i],1)),e1[b[i]].pb(mp(a[i],1));
	tl=1,tr=1e18;int pp=-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (work(p,Mid)>L)tr=Mid-1;
		else pp=Mid,tl=Mid+1;
	}cnt=0;
	puts("YES");
	for (int i=1;i<=m;i++)
	{
		if (w[i]!=0)cout<<u[i]-1<<' '<<v[i]-1<<' '<<w[i]<<endl;
		else
		{
			cnt++;
			if (cnt<p)cout<<u[i]-1<<' '<<v[i]-1<<' '<<1<<endl;
			if (cnt==p)cout<<u[i]-1<<' '<<v[i]-1<<' '<<pp<<endl;
			if (cnt>p)cout<<u[i]-1<<' '<<v[i]-1<<' '<<(int)(1e18)<<endl;
		}
	}
	return 0;
}