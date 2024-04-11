#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e9;
const int M=4e5+10;
int n1,n2,m,q,s,t,mat[M],u[M],v[M],vis[M],dep[M],S,vis2[M];
set<int>res;
vector<int>E[M];

struct edge
{
	int v,w,next;
}e[M<<2];int head[M],cur[M],tot=1;

void add(int u,int v,int w){e[++tot].v=v,e[tot].next=head[u],e[tot].w=w,head[u]=tot;}
void adde(int u,int v,int w){add(u,v,w),add(v,u,0);}

bool bfs(int s,int t)
{
	queue<int>q;q.push(s);
	memset(dep,0,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	dep[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=head[u];i;i=e[i].next)
			if (e[i].w&&!dep[e[i].v])
				dep[e[i].v]=dep[u]+1,q.push(e[i].v);
	}
	return dep[t];
}

int dfs(int s,int t,int minn)
{
	if (s==t)return minn;
	int res=0;
	for (int i=cur[s];i;i=e[i].next)
	{
		cur[s]=i;
		if (dep[e[i].v]!=dep[s]+1||!e[i].w)continue;
		int tmp=dfs(e[i].v,t,min(minn,e[i].w));
		e[i].w-=tmp,res+=tmp,e[i^1].w+=tmp,minn-=tmp;
		if (minn==0)break;
	}
	return res;
}

void dinic(int s,int t){while(bfs(s,t))dfs(s,t,inf);}

int f(int x){return x<=n1?x:-(x-n1);}

void dfs2(int x)
{
	if (vis[x])return;
	vis[x]=1;
	if (x<=n1)dfs2(u[mat[x]]==x?v[mat[x]]:u[mat[x]]);
	else for (auto y:E[x])dfs2(y);
}

signed main()
{
	n1=read(),n2=read(),m=read(),q=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read()+n1;
		adde(u[i],v[i],1);
		E[u[i]].pb(v[i]),E[v[i]].pb(u[i]);
	}
	s=n1+n2+1,t=s+1;
	for (int i=1;i<=n1;i++)adde(s,i,1);
	for (int i=n1+1;i<=n1+n2;i++)adde(i,t,1);
	dinic(s,t);
	for (int i=1;i<=m;i++)
		if (!e[i<<1].w)mat[u[i]]=mat[v[i]]=i,res.insert(i),S+=i,vis2[u[i]]=vis2[v[i]]=1;
	for (int i=n1+1;i<=n1+n2;i++)if (!vis2[i])dfs2(i);
	vector<int>v;
	for (int i=1;i<=n1;i++)if (vis[i])v.pb(i);
	for (int i=n1+1;i<=n1+n2;i++)if (!vis[i])v.pb(i);
	while(q--)
	{
		int opt=read();
		if (opt==2)
		{
			cout<<res.size()<<'\n';
			for (auto x:res)cout<<x<<' ';
			cout<<'\n';
			fflush(stdout);
//			cerr<<"===\n";
		}
		else
		{
			int x=v.back();v.pop_back();
			S-=mat[x],res.erase(mat[x]);
			cout<<"1\n"<<f(x)<<'\n'<<S<<'\n';
			fflush(stdout);
//			cerr<<"===\n";
		}
	}
	return 0;
}