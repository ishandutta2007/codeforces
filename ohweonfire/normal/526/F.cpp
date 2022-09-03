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
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=300111;

int n,a[maxn];

#define ls (t<<1)
#define rs ((t<<1)|1)
namespace sgt
{
	struct node
	{
		int mn,mncnt,delta;
		void add(int x)
		{
			mn+=x;
			delta+=x;
		}
	};
	node seg[1100111];
	void push(int t)
	{
		if(seg[t].delta)
		{
			seg[ls].add(seg[t].delta);
			seg[rs].add(seg[t].delta);
			seg[t].delta=0;
		}
	}
	void pull(int t)
	{
		seg[t].mn=min(seg[ls].mn,seg[rs].mn);
		seg[t].mncnt=(seg[ls].mn==seg[t].mn?seg[ls].mncnt:0)+(seg[rs].mn==seg[t].mn?seg[rs].mncnt:0);
	}
	
	void build(int tl,int tr,int t)
	{
		seg[t].mn=inf;seg[t].delta=0;seg[t].mncnt=tr-tl+1;
		if(tl==tr)return;
		int mid=(tl+tr)>>1;
		build(tl,mid,ls);
		build(mid+1,tr,rs);
	}
	void modify(int p,int tl,int tr,int t)
	{
		if(tl==tr)
		{
			seg[t].mn=p;
			seg[t].mncnt=1;
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(p<=mid)modify(p,tl,mid,ls);
		else modify(p,mid+1,tr,rs);
		pull(t);
	}
	void add(int l,int r,int v,int tl,int tr,int t)
	{
		if(l<=tl&&tr<=r)
		{
			seg[t].add(v);
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(l<=mid)add(l,r,v,tl,mid,ls);
		if(r>mid)add(l,r,v,mid+1,tr,rs);
		pull(t);
	}
	int query(){return seg[1].mncnt;}
	void debug(int tl,int tr,int t)
	{
		if(tl==tr)
		{
			printf("p= %d val= %d\n",tl,seg[t].mn);
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		debug(tl,mid,ls);
		debug(mid+1,tr,rs);
	}
}

int mnpos[maxn],mntot,mxpos[maxn],mxtot;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		int x,y;get2(x,y);
		a[x]=y;
	}
	
	LL ans=0;
	sgt::build(1,n,1);
	for(int i=1;i<=n;i++)
	{
		sgt::modify(i,1,n,1);
		while(mntot&&a[mnpos[mntot]]>a[i])
		{
			sgt::add(mnpos[mntot-1]+1,mnpos[mntot],a[mnpos[mntot]]-a[i],1,n,1);
			mntot--;
		}
		while(mxtot&&a[mxpos[mxtot]]<a[i])
		{
			sgt::add(mxpos[mxtot-1]+1,mxpos[mxtot],a[i]-a[mxpos[mxtot]],1,n,1);
			mxtot--;
		}
		
		mnpos[++mntot]=i;
		mxpos[++mxtot]=i;
		
		ans+=sgt::query();
	}
	printendl(ans);
	return 0;
}