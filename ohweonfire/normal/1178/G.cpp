// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
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
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<LL,LL> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=200111;
const int B=200;
int n,q,a[maxn],b[maxn],fa[maxn],ord[maxn];
bool cmp_by_b(int x,int y){return b[x]<b[y];}

int bl[maxn/B+100],br[maxn/B+100],bid[maxn],btot;

inline bool chk(const pii&a,const pii&b,const pii&c)
{
	double Tl=((double)a.ss-b.ss)*((double)c.ff-a.ff),Tr=((double)b.ff-a.ff)*((double)a.ss-c.ss);
	if(abs(Tl-Tr)>1e16)return Tl>Tr;
	return (a.ss-b.ss)*(c.ff-a.ff)-(b.ff-a.ff)*(a.ss-c.ss)>=0;
}
inline LL val(const pii&a,int x){return a.ff*x+a.ss;}

struct block
{
	pii mn[B+1],mx[B+1];
	int mntot,mxtot,mnit,mxit,cur_x;
	block(){cur_x=0;}
	
	void addmn(LL a,LL b)//ax+b
	{
		if(mntot&&mn[mntot-1].ff==a)
		{
			if(mn[mntot-1].ss>b)return;
			else mntot--;
		}
		while(mntot>1&&chk(mn[mntot-2],mn[mntot-1],mp(a,b)))mntot--;
		mn[mntot++]=mp(a,b);
	}
	void addmx(LL a,LL b)//ax+b
	{
		if(mxtot&&mx[mxtot-1].ff==a)
		{
			if(mx[mxtot-1].ss<b)return;
			else mxtot--;
		}
		while(mxtot>1&&chk(mx[mxtot-2],mx[mxtot-1],mp(a,b)))mxtot--;
		mx[mxtot++]=mp(a,b);
	}
	void getmn()
	{
		while(mnit<mntot-1&&val(mn[mnit],cur_x)<val(mn[mnit+1],cur_x))mnit++;
	}
	void getmx()
	{
		while(mxit<mxtot-1&&val(mx[mxit],cur_x)>val(mx[mxit+1],cur_x))mxit++;
	}
	
	void rebuild(int l,int r)
	{
		mntot=mxtot=0;mnit=mxit=0;
		for(int i=l;i<=r;i++)addmn(b[ord[i]],(LL)a[ord[i]]*b[ord[i]]);
		for(int i=r;i>=l;i--)addmx(b[ord[i]],(LL)a[ord[i]]*b[ord[i]]);
		getmn();
		getmx();
	}
	void modify(int x)
	{
		cur_x+=x;
		getmn();
		getmx();
	}
	LL querymx(){return val(mn[mnit],cur_x);}
	LL querymn(){return val(mx[mxit],cur_x);}
};
block blk[maxn/B+100];

void modify(int l,int r,int v)
{
	int idl=bid[l],idr=bid[r];
	if(idl==idr)
	{
		for(int i=l;i<=r;i++)a[i]+=v;
		blk[idl].rebuild(bl[idl],br[idl]);
		return;
	}
	if(bl[idl]!=l)
	{
		for(int i=l;i<=br[idl];i++)a[i]+=v;
		blk[idl].rebuild(bl[idl],br[idl]);
		idl++;
	}
	if(br[idr]!=r)
	{
		for(int i=bl[idr];i<=r;i++)a[i]+=v;
		blk[idr].rebuild(bl[idr],br[idr]);
		idr--;
	}
	for(int i=idl;i<=idr;i++)blk[i].modify(v);
}
inline LL getval(int i){return (LL)(a[i]+blk[bid[i]].cur_x)*b[i];}
LL query(int l,int r)
{
	int idl=bid[l],idr=bid[r];
	LL mn=getval(l),mx=mn;
	if(idl==idr)
	{
		for(int i=l;i<=r;i++)
		{
			LL tmp=getval(i);
			mn=min(mn,tmp);
			mx=max(mx,tmp);
		}
		return max(mx,-mn);
	}
	if(bl[idl]!=l)
	{
		for(int i=l;i<=br[idl];i++)
		{
			LL tmp=getval(i);
			mn=min(mn,tmp);
			mx=max(mx,tmp);
		}
		idl++;
	}
	if(br[idr]!=r)
	{
		for(int i=bl[idr];i<=r;i++)
		{
			LL tmp=getval(i);
			mn=min(mn,tmp);
			mx=max(mx,tmp);
		}
		idr--;
	}
	for(int i=idl;i<=idr;i++)
	{
		mn=min(mn,blk[i].querymn());
		mx=max(mx,blk[i].querymx());
	}
	return max(mx,-mn);
}


vector<int> g[maxn];
int dfn[maxn],edfn[maxn],timer;

void dfs(int x)
{
	dfn[x]=++timer;
	for(auto v:g[x])dfs(v);
	edfn[x]=timer;
}

void re_number(int*a,int*ord)
{
	static int tmp[maxn];
	for(int i=1;i<=n;i++)tmp[ord[i]]=a[i];
	for(int i=1;i<=n;i++)a[i]=tmp[i];
}

int main()
{
	get2(n,q);
	for(int i=2;i<=n;i++)get1(fa[i]);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=n;i++)get1(b[i]);
	
	for(int i=2;i<=n;i++)
	{
		a[i]+=a[fa[i]];
		b[i]+=b[fa[i]];
		g[fa[i]].pb(i);
	}
	
	dfs(1);
	re_number(a,dfn);re_number(b,dfn);
	
	for(int i=1;i<=n;i++)ord[i]=i;
	for(int i=1;i<=n;i+=B)
	{
		btot++;
		for(int j=i;j<=n&&j<i+B;j++)
		{
			if(!bl[btot])bl[btot]=j;br[btot]=j;
			bid[j]=btot;
		}
		sort(ord+bl[btot],ord+br[btot]+1,cmp_by_b);
		blk[btot].rebuild(bl[btot],br[btot]);
	}
	
	int tp,x,y;
	while(q--)
	{
		get2(tp,x);
		if(tp==1)
		{
			get1(y);
			modify(dfn[x],edfn[x],y);
		}
		else printf("%lld\n",query(dfn[x],edfn[x]));
	}
	
	return 0;
}