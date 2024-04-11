// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int T=(1<<30)-1;
struct centroid
{
	int head[400111],nxt[800111],to[800111],l[800111],tot;
	
	void addedge(int u,int v,int w=0)
	{
//		printf("addedge %d %d %d\n",u,v,w);
		nxt[++tot]=head[u];
		head[u]=tot;
		to[tot]=v;
		l[tot]=w;
		nxt[++tot]=head[v];
		head[v]=tot;
		to[tot]=u;
		l[tot]=w;
	}
	bool used[400111];
	LL dist[20][400111];
	int c[8800111][3],cc[8800111],timer,lvl,sz[400111],le[400111],ri[400111],ord[400111],back[8800111];
	vector<int> v;
	void dfs(int x,int f)
	{
		sz[x]=1;
		v.pb(x);
		for(int i=head[x];i;i=nxt[i])
			if(to[i]!=f&&!used[to[i]])
			{
				dfs(to[i],x);
				sz[x]+=sz[to[i]];
			}
	}
	void getroot(int &mx)
	{
		v.clear();
		dfs(mx,0);
		int all=sz[mx],ans=all;
		for(int _=0;_<(int)v.size();_++)
		{
			int x=v[_],val=0;
			for(int i=head[x];i;i=nxt[i])
				if(!used[to[i]]&&sz[x]>sz[to[i]])
					val=max(val,sz[to[i]]);
				else if(!used[to[i]])
					val=max(val,all-sz[x]);
			if(val<ans)
			{
				ans=val;
				mx=x;
			}
		}
	}
	void dfs2(int x,LL dis,int f)
	{
		dist[lvl][x]=dis;
		for(int i=head[x];i;i=nxt[i])
			if(to[i]!=f&&!used[to[i]])
				dfs2(to[i],dis+l[i],x);
	}
	int decompose(int root,int lvl=0)
	{
		getroot(root);
		this->lvl=lvl;
		dfs2(root,0,0);
		
		le[root]=ord[root]=++timer;
		back[root]=root;
		used[root]=1;
		
		for(int i=head[root];i;i=nxt[i])
			if(!used[to[i]])
				c[root][cc[root]++]=decompose(to[i],lvl+1);
		ri[root]=timer;
		return root;
	}
	
	int cnt[8800111];
	LL sum[8800111],cnt2[8800111];
	int update(int x,int v,int lvl=0)
	{
//		printf("update %d %d %d\n",x,v,lvl);
		int node=++timer;
		cnt[node]=cnt[x]+1;
		sum[node]=sum[x]+dist[lvl][v];
		back[node]=back[x];
		for(int i=0;i<cc[back[x]];i++)
			if(le[back[c[x][i]]]<=ord[v]&&ord[v]<=ri[back[c[x][i]]])
			{
				c[node][i]=update(c[x][i],v,lvl+1);
				cnt2[c[node][i]]=cnt2[c[x][i]]+dist[lvl][v];
			}
			else c[node][i]=c[x][i];
		return node;
	}
	LL query(int x,int v,int lvl=0)
	{
		LL ret=sum[x];
		for(int i=0;i<cc[back[x]];i++)
			if(le[back[c[x][i]]]<=ord[v]&&ord[v]<=ri[back[c[x][i]]])
				ret+=(cnt[x]-cnt[c[x][i]])*dist[lvl][v]-cnt2[c[x][i]]+query(c[x][i],v,lvl+1);
		return ret;
	}
}cen;
int head[200111],nxt[400111],to[400111],l[400111],tot,sz,deg[200111];
int n,q,a[200111],ro[200111];
void addedge(int u,int v,int w)
{
	deg[u]++;deg[v]++;
	nxt[++tot]=head[u];
	head[u]=tot;
	to[tot]=v;
	l[tot]=w;
	nxt[++tot]=head[v];
	head[v]=tot;
	to[tot]=u;
	l[tot]=w;
}
void binarize(int x,int f,int root=0)
{
	if(deg[x]+(root^1)<=3)
	{
		for(int i=head[x];i;i=nxt[i])
			if(to[i]!=f)
			{
				cen.addedge(x,to[i],l[i]);
				binarize(to[i],x);
			}
		return;
	}
	int flag=0,last=x;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==f)continue;
		if(flag==0)
		{
			flag=1;
			cen.addedge(x,to[i],l[i]);
			binarize(to[i],x);
			flag=1;
		}
		else
		{
			sz++;
			cen.addedge(last,sz);
			cen.addedge(sz,to[i],l[i]);
			last=sz;
			binarize(to[i],x);
		}
	}
}
int main()
{
	get2(n,q);
	sz=n;
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1,u,v,w;i<n;i++)
	{
		get3(u,v,w);
		addedge(u,v,w);
	}
	binarize(1,0,1);
	ro[0]=cen.decompose(1);
	for(int i=1;i<=n;i++)ro[i]=cen.update(ro[i-1],a[i]);
//	for(int i=0;i<20;i++)for(int j=1;j<=n;j++)printf("%d%c",cen.dist[i][j],j==n?'\n':' ');
	LL ans=0;
	for(int i=1,t;i<=q;i++)
	{
		get1(t);
		if(t==1)
		{
			int a,b,c;get3(a,b,c);a^=ans;b^=ans;c^=ans;
			ans=cen.query(ro[b],c)-cen.query(ro[a-1],c);
			printendl(ans);
			ans&=T;
		}
		else
		{
			int x;get1(x);x^=ans;
			ro[x]=cen.update(ro[x-1],a[x+1]);
			swap(a[x],a[x+1]);
		}
	}
	return 0;
}