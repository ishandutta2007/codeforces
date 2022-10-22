#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=1e5+10;
int n,q,a[M<<1];
string s;

int max(int a,int b){return a>b?a:b;}
int max(int a,int b,int c){return max(a,max(b,c));}
int max(int a,int b,int c,int d){return max(max(a,b),max(c,d));}

struct segment_tree
{
	struct tree
	{
		int tl,tr,lmax,rmin,val,sum,valm,Lmax,Rmax;
	}t[M<<3];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define lmax(x) t[(x)].lmax
	#define rmin(x) t[(x)].rmin
	#define val(x) t[(x)].val
	#define sum(x) t[(x)].sum
	#define valm(x) t[(x)].valm
	#define Lmax(x) t[(x)].Lmax
	#define Rmax(x) t[(x)].Rmax
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		sum(k)=sum(lson)+sum(rson),
		val(k)=max(val(lson),val(rson),Lmax(rson)-rmin(lson),Rmax(lson)+lmax(rson)),
		valm(k)=max(valm(lson)+sum(rson),valm(rson)-sum(lson)),
		Lmax(k)=max(Lmax(lson),valm(lson)+lmax(rson),Lmax(rson)-sum(lson)),
		Rmax(k)=max(Rmax(rson),valm(rson)-rmin(lson),Rmax(lson)+sum(rson)),
		lmax(k)=max(lmax(lson),lmax(rson)+sum(lson)),
		rmin(k)=min(rmin(rson),rmin(lson)+sum(rson));
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)
		{
			Lmax(k)=Rmax(k)=val(k)=valm(k)=1,sum(k)=a[l],
			rmin(k)=min(a[l],0ll),lmax(k)=max(a[l],0ll);
			return;
		}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==r(k))
		{
			Lmax(k)=Rmax(k)=val(k)=valm(k)=1,sum(k)=a[l],
			rmin(k)=min(a[l],0ll),lmax(k)=max(a[l],0ll);
			return;
		}
		update(lson,l),update(rson,l);
		pushup(k);
	}
	int query(){return val(1);}
}T;

signed main()
{
	n=read(),q=read();
	cin>>s;
	for (int i=0;i<2*n-2;i++)
		a[i+1]=s[i]=='('?1:-1;
	T.build(1,1,2*n-2);
	printf("%lld\n",T.query());
	while(q--)
	{
		int l=read(),r=read();
		swap(a[l],a[r]);
		T.update(1,l),T.update(1,r);
		printf("%lld\n",T.query());
	}
	return 0;
}