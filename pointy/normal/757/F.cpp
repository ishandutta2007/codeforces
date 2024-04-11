//BY LITTLE09
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=600005;
vector<int>t[N],v[N],dt[N];
int d[N][2],n,m,rk[N],cnt;
int fa[N][25],deth[N];
const ll inf=1000000000000000000;
int td[N],nxt[N];
ll vd[N];
int h[N];
ll dis[N];
int Cnt=0;
bool used[N],di[N];
priority_queue<pair<ll,int> >qd; 
void dijkstra(int s)
{
	for (int i=0;i<=n;i++) dis[i]=inf;
    dis[s]=0;
    qd.push(make_pair(0,s));
    while (qd.size())
    {
    	int x=qd.top().second;
    	qd.pop();
    	if (used[x]) continue;
    	used[x]=1;
    	for (int j=h[x];j;j=nxt[j])
    	{
    		if (dis[td[j]]>dis[x]+vd[j])
    		{
    			dis[td[j]]=dis[x]+vd[j];
    			qd.push(make_pair(-dis[td[j]],td[j]));
			}
		}
	}
}
void add1(int a,int b,int c)
{
    td[++Cnt]=b;
    vd[Cnt]=c;
    nxt[Cnt]=h[a];
    h[a]=Cnt;
}
void addedge(int x,int y)
{
	//cout << x <<" " << y << endl;
	di[x]=1,di[y]=1;
	d[y][0]++,d[x][1]++;
	t[x].push_back(y);
	v[y].push_back(x);
}
queue<int>q;
void tp(int s)
{
	for (int i=1;i<=n;i++)
	{
		if (d[i][1]==0&&di[i]==1) 
		{
			q.push(i);
			//cout << i << endl;
		}
	}
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		rk[++cnt]=u;
		for (int i=0;i<v[u].size();i++) 
		{
			//cout << v[u][i] << endl;
			d[v[u][i]][1]--;
			if (d[v[u][i]][1]==0) q.push(v[u][i]);
		}
	}
}
void add(int u,int f)
{
	fa[u][0]=f;
	deth[u]=deth[f]+1;
	for (int i=1;i<=20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	dt[f].push_back(u);
}
int LCA(int x,int y)
{
	if (deth[x]<deth[y]) swap(x,y);
	for (int i=20;i>=0;i--) if (deth[fa[x][i]]>=deth[y]) x=fa[x][i];
    if (x==y) return x;
    for (int i=20;i>=0;i--)
    {
    	if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
int size[N];
void dfs(int u,int f)
{
	size[u]=1;
	for (int i=0;i<dt[u].size();i++)
	{
		dfs(dt[u][i],u);
		size[u]+=size[dt[u][i]];
	}
}
int work(int s)
{
	tp(s);
	//for (int i=1;i<=cnt;i++) cout << rk[i] << " ";
	//cout << endl;
	for (int i=1;i<=cnt;i++)
	{
		if (i==1) 
		{
			add(rk[1],0);
			continue;
		}
		int u=rk[i],v=t[u][0];
		for (int j=1;j<t[u].size();j++) 
		{
			v=LCA(v,t[u][j]);
		}
		add(u,v);
	}
	dfs(0,-1);
	int res=0;
	for (int i=1;i<=n;i++) if (i!=s&&di[i]) res=max(res,size[i]);
	return res;
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
struct edge
{
	int x,y;
	ll z;
}a[N];
int main()
{
	n=read(),m=read();
	int s=read();
	for (int i=1;i<=m;i++)
	{
		a[i].x=read(),a[i].y=read(),a[i].z=read();
		add1(a[i].x,a[i].y,a[i].z),add1(a[i].y,a[i].x,a[i].z);
	}
	dijkstra(s);
	for (int i=1;i<=m;i++)
	{
		int x=a[i].x,y=a[i].y;
		if (dis[x]+a[i].z==dis[y]) addedge(y,x);
		else if (dis[y]+a[i].z==dis[x]) addedge(x,y);
	}
	cout << work(s) << endl;
	return 0;
}