#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN=4557430888798830399ll;
const int M=1e5+10;
const int D=5e5;
int f[M],n,q;
vector<pair<int,int> >e[M*10];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define lson (k<<1)
#define rson (k<<1|1)
#define l(x) t[(x)].tl
#define r(x) t[(x)].tr

struct tree
{
	int tl,tr;
}t[M*10];

void build(int k,int l,int r)
{
	l(k)=l,r(k)=r;
	if (l==r)
	{
		f[l]=k;
		return;
	}
	int Mid=(l+r)>>1;
	e[k].pb(mp(lson,0));e[k].pb(mp(rson,0));
	e[lson+D].pb(mp(k+D,0));e[rson+D].pb(mp(k+D,0));
//	cout<<k<<' '<<lson<<endl;
//	cout<<k<<' '<<rson<<endl;
//	cout<<lson+D<<' '<<k+D<<endl;
//	cout<<rson+D<<' '<<k+D<<endl;
	build(lson,l,Mid),build(rson,Mid+1,r);
}

void add(int k,int u,int l,int r,int w,int opt)
{
	if (l<=l(k)&&r>=r(k))
	{
		if (opt)e[k+D].pb(mp(u,w));//,cout<<k+D<<' '<<u<<' '<<w<<endl;
		else e[u].pb(mp(k,w));//,cout<<u<<' '<<k<<' '<<w<<endl;
		return;
	}
	if (r<l(k)||l>r(k))return;
	add(lson,u,l,r,w,opt),add(rson,u,l,r,w,opt);
}


bool vis[M*10];
int dis[M*10],s;

struct node
{
	int id,w;
	bool operator < (const node &b)const{return b.w<w;}
};

priority_queue<node> qq;

void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));node a;a.id=s,a.w=0,dis[s]=0;qq.push(a);
	while(!qq.empty())
	{
		node k=qq.top();qq.pop();
		if (vis[k.id])continue;
		vis[k.id]=1;
		for (int i=0;i<e[k.id].size();i++)
		{
			int to=e[k.id][i].first,w=e[k.id][i].second;
			if (dis[to]>dis[k.id]+w)
			{
				dis[to]=dis[k.id]+w;
				if (!vis[to])
				{
					node p;p.id=to,p.w=dis[to];
					qq.push(p);
				}
			}
		}
	}
}

signed main()
{
	n=read(),q=read(),s=read();
	build(1,1,n);
//	puts("debug");
	for (int i=1;i<=q;i++)
	{
		int opt=read();
		if (opt==1)
		{
			int u=read(),v=read(),w=read();
			e[f[u]].pb(mp(f[v],w));
//			cout<<u<<' '<<v<<' '<<w<<endl;
		}
		else
		{
			int u=read(),l=read(),r=read(),w=read();
			add(1,f[u],l,r,w,opt&1);
		}
	}
	for (int u=1;u<=n;u++)
		e[f[u]].pb(mp(f[u]+D,0)),e[f[u]+D].pb(mp(f[u],0));
//	puts("debug");
//	for (int i=1;i<=n;i++)cout<<f[i]<<' ';
//	puts("");
	dij(f[s]);
	for (int i=1;i<=n;i++)
		if (dis[f[i]]!=MAXN)
			cout<<dis[f[i]]<<' ';
		else cout<<"-1 ";
	return 0;
}