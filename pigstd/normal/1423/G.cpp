#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
const int N=2e5;
int n,a[M],q,tot;
map<int,int>tt; 
struct node
{
	int l,r,w;
	bool operator<(const node& o) const
	{
		return l<o.l;
	}
};
set<pii>s[M];set<node>t;

pii operator + (pii a,pii b){return mp(a.x+b.x,a.y+b.y);}

struct segment_tree
{
	struct tree
	{
		int tl,tr,val1,val2;
	}t[M<<2];int ed[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val1(x) t[(x)].val1
	#define val2(x) t[(x)].val2
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void upd(int k,int w)
	{
//		cout<<k<<' '<<w<<'\n';
		int now=ed[k];
		while(now)val1(now)+=w*k,val2(now)+=w,now>>=1;
	}
	pii query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return mp(val1(k),val2(k));
		if (l(k)>r||r(k)<l)return mp(0,0);
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

void insert(int w,int l,int r)
{
//	if (w<=3)cout<<w<<'i'<<l<<' '<<r<<'\n';
	auto p1=s[w].lower_bound(mp(l,r)),p2=p1;p2--;
	T.upd((*p1).x-(*p2).y,-1),T.upd((*p1).x-r,1),T.upd(l-(*p2).y,1); 
	t.insert((node){l,r,w});s[w].insert(mp(l,r));
}

void del(int w,int l,int r)
{
//	if (w<=3)cout<<w<<'d'<<l<<' '<<r<<'\n';
	t.erase((node){l,r,w});s[w].erase(mp(l,r));
	auto p1=s[w].lower_bound(mp(l,r)),p2=p1;p2--;
	T.upd((*p1).x-(*p2).y,1),T.upd((*p1).x-r,-1),T.upd(l-(*p2).y,-1); 
}

void split(int pos)
{
	if (pos>n)return;
	auto p=t.upper_bound((node){pos,0,0});p--;
	auto x=*p;
	if (x.r==pos)return;
	del(x.w,x.l,x.r);
	insert(x.w,x.l,pos);
	insert(x.w,pos+1,x.r);
}

signed main()
{
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	n=read(),q=read();T.build(1,1,n+1);
//	for (int i=1;i<=N;i++)s[i].insert(mp(0,0)),s[i].insert(mp(n+1,n+1));
	t.insert((node){0,0,0}),t.insert((node){n+1,n+1,0});
	for (int i=1;i<=n;i++)
	{
		int tmp=read();
		if (!tt[tmp])tt[tmp]=++tot,s[tot].insert(mp(0,0)),s[tot].insert(mp(n+1,n+1)),T.upd(n+1,1); 
		insert(tt[tmp],i,i);
	}
	while(q--)
	{
		int opt=read();
		if (opt==1)
		{
			int l=read(),r=read(),w=read();
			if (!tt[w])tt[w]=++tot,s[tot].insert(mp(0,0)),s[tot].insert(mp(n+1,n+1)),T.upd(n+1,1);
			w=tt[w];
			split(l-1),split(r);
			while(1)
			{
				auto p=*t.upper_bound((node){l-1,0,0});
				if (p.r>r)break;
				del(p.w,p.l,p.r);
			}
			insert(w,l,r);
		}
		else
		{
			int k=read(),res=tot*(n-k+1);
			auto x=T.query(1,k+1,n+1);
			res-=x.x-x.y*k;
			cout<<res<<'\n';
		}
	}
	return 0;
}
/*
 3500 
*/