#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=4e5+5;
const int inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int exgcd(int x,int y,int &tx,int &ty)
{
	if (!y) return tx=1,ty=0,x;
	int g=exgcd(y,x%y,tx,ty),xx=tx,yy=ty;
	tx=yy;
	ty=xx-(x/y)*yy;
	return g;
}
namespace minpath
{
	bool vis[N];
	int n,dis[N];
	struct edge{int to,val;};
	vector<edge>e[N];
	void add_edge(int u,int v,int w){e[u].push_back((edge){v,w});}
	void send(int _n)
	{
		n=_n;
		for (int i=0;i<=n;i++) e[i].clear();
	}
	struct node
	{
		int pos,val;
		bool operator <(const node &a)const
		{
			return val>a.val;
		}
	};
	int solve(int S)
	{
		for (int i=0;i<=n;i++) vis[i]=0;
		for (int i=0;i<=n;i++) dis[i]=inf;
		priority_queue<node>q;
		q.push((node){S,dis[S]=0});
		while (!q.empty())
		{
			int now=q.top().pos; q.pop();
			if (vis[now]) continue;
			vis[now]=1;
			for (edge i:e[now])
			{
				int to=i.to,val=i.val;
				if (dis[to]>dis[now]+val)
				{
					dis[to]=dis[now]+val;
					q.push((node){to,dis[to]});
				}
			}
		}
		int ret=0;
		for (int i=0;i<=n;i++) ret=max(ret,dis[i]);
		return ret;
	}
}
vector<int>a[N],b[N];
int solve(int n,int m,int k)
{
	if (n<m) swap(n,m),swap(a[k],b[k]);
	if ((int)(a[k].size()+b[k].size())==n+m) return -1;
	map<int,int>mp;
	for (int i:a[k]) mp[i]++;
	for (int i:b[k]) mp[i]++;
	if ((int)(a[k].size()+b[k].size())>=n)
	{
		bool flag=1;
		for (int i=0;i<n;i++)
		if (!mp.count(i)) flag=0;
		if (flag)
		{
			for (int i=m-1;i>=0;i--)
			if (mp[i]<2) return i;
			assert(false);
		}
	}
	int S=0,cnt=0;
	vector<int>p;
	for (auto i:mp) p.push_back(i.first);
	for (auto &i:mp) i.second=++cnt;
	for (int i:p) if (!mp.count((i-m+n)%n)) mp[(i-m+n)%n]=++cnt;
	minpath::send(cnt);
	for (int i:p)
		minpath::add_edge(S,mp[i],i),
		minpath::add_edge(mp[(i-m+n)%n],mp[i],m);
	int x,y;
	vector<int>q(p.size());
	exgcd(m,n,x,y);
	x=(x%n+n)%n;
	for (int i=1;i<(int)p.size();i++) q[i]=x*(p[i]-p[0])%n;
	vector<int>rk(p.size());
	for (int i=0;i<(int)p.size();i++) rk[i]=i;
	sort(rk.begin(),rk.end(),[&](int x,int y){return q[x]<q[y];});
	for (int i=0;i<(int)p.size();i++)
	{
		int u=rk[i],v=rk[(i+1)%p.size()];
		minpath::add_edge(mp[p[u]],mp[(p[v]-m+n)%n],(q[v]-q[u]+n-1)%n*m);
	}
	return minpath::solve(S);
}

signed main()
{
	int n=read(),m=read(),g=gcd(n,m);
	if (g>2e5) return puts("-1"),0;
	int B=read();
	for (int i=1;i<=B;i++)
	{
		int x=read();
		a[x%g].push_back(x/g);
	}
	int G=read();
	for (int i=1;i<=G;i++)
	{
		int x=read();
		b[x%g].push_back(x/g);
	}
	for (int i=0;i<g;i++)
	if (a[i].empty()&&b[i].empty()) return puts("-1"),0;
	int ans=0;
	for (int i=0;i<g;i++) ans=max(ans,solve((n-1)/g+1,(m-1)/g+1,i)*g+i);
	print(ans);
	
	return 0;
}