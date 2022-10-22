#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
#define l(x) tt[(x)].tl
#define r(x) tt[(x)].tr
#define val(x) tt[(x)].val
#define lson k<<1
#define rson k<<1|1
using namespace std;
 
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,m,opt[M],x[M],y[M],q;
map<pair<pair<int,int>,int>,int>t;
vector<pair<pair<int,int>,int>>V;
map<pair<int,int>,int>t2;

struct XXJ
{
	int a[40];
	void insert(int x)
	{
		for (int i=30;i>=0;i--)
			if ((x>>i)&1)
			{
				if (a[i])x^=a[i];
				else {a[i]=x;break;}
			}
	}
	int getmax(int x)
	{
		for (int i=30;i>=0;i--)x=min(x,x^a[i]);
		return x;
	}
}now;

struct dsu
{
	int f[M],sz[M],w[M],top;
	pair<int,int>st[M];
	pair<int,int>find(int x){int res=0;while(f[x]!=x)res^=w[x],x=f[x];return mp(x,res);}
	//int check(int x,int y){auto a=find(x),b=find(y);if (a.x!=b.x)return -1;else return a.y^b.y;}
	void init(int n){for (int i=1;i<=n;i++)f[i]=i,sz[i]=1;}
	void merge(int x,int y,int W)
	{
		if (sz[x]>sz[y])swap(x,y);
		sz[y]+=sz[x],f[x]=y,w[x]=W,st[++top]=mp(x,y);
	}
	void clear()
	{
		auto x=st[top--];
		sz[x.y]-=sz[x.x],f[x.x]=x.x,w[x.x]=0;
	}
}T;

struct tree
{
	int tl,tr;
	vector<pair<pair<int,int>,int>>val;
}tt[M<<2];

void build(int k,int l,int r)
{
	l(k)=l,r(k)=r;
	if (l==r)return;
	int Mid=(l+r)>>1;
	build(lson,l,Mid),build(rson,Mid+1,r);
}

void update(int k,int l,int r,pair<pair<int,int>,int>x)
{
//	if (k==1)cout<<l<<' '<<r<<' '<<x.x.x<<' '<<x.x.y<<' '<<x.y<<endl;
	if (l(k)>r||r(k)<l)return;
	if (l(k)>=l&&r(k)<=r){val(k).pb(x);return;}
	update(lson,l,r,x),update(rson,l,r,x);
}

void work(int k)
{
	XXJ bef=now;int cnt=0;
	for (auto x:val(k))
	{
		auto a=T.find(x.x.x),b=T.find(x.x.y);
		if (a.x==b.x)now.insert(x.y^a.y^b.y);
		else T.merge(a.x,b.x,x.y^a.y^b.y),cnt++;
	}
	if (l(k)==r(k))
	{
		if (opt[l(k)]==3)
		{
			auto a=T.find(x[l(k)]),b=T.find(y[l(k)]);
			printf("%lld\n",now.getmax(a.y^b.y));
		}
	}
	else work(lson),work(rson);
	now=bef;for (int i=1;i<=cnt;i++)T.clear();
}

signed main()
{
	n=read(),m=read();T.init(n);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();t2[mp(u,v)]=w;
		t[mp(mp(u,v),w)]=1,V.pb(mp(mp(u,v),w));
	}
	build(1,1,m);q=read();
	for (int i=1;i<=q;i++)
	{
		opt[i]=read(),x[i]=read(),y[i]=read();
		if (opt[i]==1)
		{
			int w=read();t2[mp(x[i],y[i])]=w;
			V.pb(mp(mp(x[i],y[i]),w));t[mp(mp(x[i],y[i]),w)]=i;
		}
		else if (opt[i]==2)
		{
			int w=t2[mp(x[i],y[i])];
			update(1,t[mp(mp(x[i],y[i]),w)],i,mp(mp(x[i],y[i]),w));
			t[mp(mp(x[i],y[i]),w)]=-1; 
		}
	}
	for (auto x:V)if (t[x]!=-1)update(1,t[x],q,x);
	work(1);
	return 0;
}