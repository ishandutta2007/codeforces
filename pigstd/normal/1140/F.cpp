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

const int M=3e5+10;
int n,q,ans;
map<pair<int,int>,int>t;

struct dsu
{
	int f[M<<1],sz1[M<<1],sz2[M<<1],top;
	pair<int,int>st[M];
	int find(int x){while(f[x]!=x)x=f[x];return x;}
	void init(int n)
	{
		for (int i=1;i<=n;i++)f[i]=i;
		for (int i=1;i<=n/2;i++)sz1[i]=1;
		for (int i=n/2+1;i<=n;i++)sz2[i]=1;
	}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y){st[++top]=mp(-1,-1);return;}
		ans-=sz1[x]*sz2[x]+sz1[y]*sz2[y];
		if (sz1[x]+sz2[x]>sz1[y]+sz2[y])swap(x,y);
		st[++top]=mp(x,y);
		sz1[y]+=sz1[x],sz2[y]+=sz2[x],f[x]=y;
		ans+=sz2[y]*sz1[y];
	}
	void clear()
	{
		auto x=st[top--];
		if (x.x==-1)return;
		ans-=sz1[x.y]*sz2[x.y];
		sz1[x.y]-=sz1[x.x],sz2[x.y]-=sz2[x.x],f[x.x]=x.x;
		ans+=sz1[x.x]*sz2[x.x]+sz1[x.y]*sz2[x.y];
	}
}T;

struct tree
{
	int tl,tr;
	vector<pair<int,int>>val;
}tt[M<<2];

void build(int k,int l,int r)
{
	l(k)=l,r(k)=r;
	if (l==r)return;
	int Mid=(l+r)>>1;
	build(lson,l,Mid),build(rson,Mid+1,r);
}

void update(int k,int l,int r,pair<int,int>x)
{
//	if (k==1)cout<<l<<' '<<r<<' '<<x.x<<' '<<x.y<<'\n';
	if (l(k)>r||r(k)<l)return;
	if (l(k)>=l&&r(k)<=r){val(k).pb(x);return;}
	update(lson,l,r,x),update(rson,l,r,x);
}

void work(int k)
{
	for (auto x:val(k))
		T.merge(x.x,x.y+n);
	if (l(k)==r(k))printf("%lld ",ans);
	else {work(lson);
		work(rson);}
	for (int i=0;i<val(k).size();i++)T.clear();
}

signed main()
{
	q=read();n=3e5;T.init(n*2);build(1,1,q);
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		if (t[mp(x,y)])update(1,t[mp(x,y)],i-1,mp(x,y)),t[mp(x,y)]=0;
		else t[mp(x,y)]=i;
	}
	for (auto x:t)if (x.y!=0)update(1,x.y,q,x.x);
	work(1);
	return 0;
}