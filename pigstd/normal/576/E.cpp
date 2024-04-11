#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define ins insert
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

const int M=5e5+10;
int n,m,q,c,col[M],x[M],y[M],a[M],b[M];
set<int>s[M];

struct node{int x,y;};

struct dsu
{
	int f[M<<1],sz[M<<1],top;
	stack<node>s;
	int find(int x){while(f[x]!=x)x=f[x];return x;}
	int Sz(){return s.size();}
	int check(int x,int y){return find(x)==find(y);}
	void init(int n){for (int i=1;i<=n;i++)f[i]=i,sz[i]=1;}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y)return;
		if (sz[x]>sz[y])swap(x,y);
		f[x]=y,sz[y]+=sz[x];s.push((node){x,y});
	}
	void clear(int now)
	{
		while(s.size()>now)
		{
			auto a=s.top();s.pop();
			sz[a.y]-=sz[a.x],f[a.x]=a.x;
		}
	}
}T[51];

struct tree
{
	int tl,tr;
	vector<int>val;
}tt[M<<2];

void build(int k,int l,int r)
{
	l(k)=l,r(k)=r;
	if (l==r)return;
	int Mid=(l+r)>>1;
	build(lson,l,Mid),build(rson,Mid+1,r);
}

void update(int k,int l,int r,int x)
{
	if (l(k)>r||r(k)<l)return;
	if (l(k)>=l&&r(k)<=r){val(k).pb(x);return;}
	update(lson,l,r,x),update(rson,l,r,x);
}

void work(int k)
{
	vector<int>v;v.resize(c+1); 
	for (int i=1;i<=c;i++)v[i]=T[i].Sz();
	for (auto p:val(k))
		T[col[p]].merge(x[p],y[p]+n),
		T[col[p]].merge(y[p],x[p]+n);
	if (l(k)==r(k))
	{
		int i=l(k);
		if (T[b[i]].check(x[a[i]],y[a[i]]))puts("NO");
		else puts("YES"),col[a[i]]=b[i];
		if (i!=q)
		{
			int p=*s[a[i]].upper_bound(i);
			if (col[a[i]]!=0)update(1,i+1,p,a[i]);
		}
	}
	else work(lson),work(rson);
	for (int i=1;i<=c;i++)T[i].clear(v[i]);
}

signed main()
{
	n=read(),m=read(),c=read(),q=read();
	for (int i=1;i<=c;i++)T[i].init(n*2);
	for (int i=1;i<=m;i++)x[i]=read(),y[i]=read();
	for (int i=1;i<=q;i++)
	{
		a[i]=read(),b[i]=read();
		s[a[i]].ins(i);
	}
	for (int i=1;i<=m;i++)s[i].ins(q);
	build(1,1,q);work(1);
	return 0;
}
/*
 
 
*/