#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>p,q;
int get(vector<int>p,vector<int>q)
{
	int n=p.size(),m=q.size(),ret=0;
	static int np[N];
	memset(np,-1,sizeof(np));
	for (int i=0;i<n;i++) np[p[i]]=i;
	for (int i=0,lst=-1,len=0;i<m;i++)
	{
		int now=np[q[i]];
		if (now<0) len=0,lst=-1;
		else if (lst+1==now) len++,lst=now;
		else lst=now,len=1;
		ret=max(ret,len);
	}
	return max(ret-1,0);
}
bool vis[N],is[N];
int a[N],b[N],nb[N],ans=0,n,s=0,t=0,fa[N],deep[N],x;
vector<int>e[N];
bool dfs0(int now,int father,int t)
{
	if (now==t) return vis[now]=1;
	for (int to:e[now])
	{
		if (to==father) continue;
		if (dfs0(to,now,t)) return vis[now]=1;
	}
	return 0;
}
void dfs1(int now,int father)
{
	deep[now]=deep[fa[now]=father]+1;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs1(to,now);
	}
}
bool getp(int now,int father,int t)
{
	if (now==t) return p.push_back(now),vis[now]=1;
	for (int to:e[now])
	{
		if (to==father) continue;
		if (getp(to,now,t)) return p.push_back(now),vis[now]=1;
	}
	return 0;
}
void go(int now,int father)
{
	for (int to:e[now])
	{
		if (to==father||!vis[to]) continue;
		ans++,swap(a[now],a[to]),go(to,now);
	}
}
int deg[N],id[N],len;
void getid(int now,int father,int t,int ID)
{
	id[now]=ID,q.push_back(now);
	if (now==t) return len=ID+(now!=x),void();
	for (int to:e[now])
	{
		if (to==father||!is[to]) continue;
		getid(to,now,t,ID+(now!=x));
	}
}
int dis[N];
int bfs()
{
	queue<int>q; q.push(x);
	if (vis[x]) return 0;
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int to:e[now])
		if (!is[to])
		{
			dis[to]=dis[now]+1,is[to]=1,q.push(to);
			if (vis[to]) return dis[to];
		}
	}
	return -1e9-7;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) if (!(a[i]=read())) s=i;
	for (int i=1;i<=n;i++) if (!(b[i]=read())) t=i;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs0(s,0,t),go(s,0),dfs1(t,0);
	int all=0;
	for (int i=1;i<=n;i++) all+=is[i]=a[i]!=b[i];
	if (!all) return print(0,' '),print(ans),0;
	int mn=0;
	for (int i=1;i<=n;i++) if (is[i]&&(!mn||deep[mn]>deep[i])) mn=i;
	is[x=fa[mn]]=1;
	for (int i=1;i<=n;i++)
	for (int j:e[i]) if (is[i]&&is[j]) deg[i]++;
	int tot=0;
	for (int i=1;i<=n;i++) if (is[i])
	{
		if (deg[i]<1||deg[i]>2) return puts("-1"),0;
		tot+=deg[i]==1;
	}
	if (tot>2) return puts("-1"),0;
	int u=0,v=0;
	for (int i=1;i<=n;i++) if (is[i]&&deg[i]==1) u?v=i:u=i;
	getid(u,0,v,0);
	int tmp=0;
	for (int i=1;i<=n;i++) nb[b[i]]=i;
	for (int i=1;i<=n;i++) if (is[i]&&i!=x)
	{
		int pos=nb[a[i]],x=id[i],y=id[pos],z=(y-x+len)%len;
		if (!tmp) tmp=z;
		else if (tmp!=z) return puts("-1"),0;
	}
	getp(s,0,t),reverse(p.begin(),p.end());
	ll A=1LL*tmp*(len+1)-get(p,q)*2; reverse(q.begin(),q.end());
	ll B=1LL*(len-tmp)*(len+1)-get(p,q)*2;
	print(u,' '),print(v,' '),print(ans+bfs()*2+min(A,B));
	
	return 0;
}