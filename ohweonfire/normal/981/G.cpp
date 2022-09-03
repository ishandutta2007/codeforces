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
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=998244353;

struct node
{
	int sz,a,b,sum;
	node(){sz=b=sum=0;a=1;}
	void apply(int na,int nb)
	{
		sum=(1ll*sum*na+1ll*sz*nb)%mod;
		a=1ll*a*na%mod;
		b=(1ll*na*b+nb)%mod;
	}
};
node seg[600111];
#define ls (t<<1)
#define rs (t<<1|1)
void pushdown(int t)
{
	if(seg[t].a!=1||seg[t].b)
	{
		seg[ls].apply(seg[t].a,seg[t].b);
		seg[rs].apply(seg[t].a,seg[t].b);
		seg[t].a=1;seg[t].b=0;
	}
}
void build(int l,int r,int t)
{
	seg[t].sz=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
}
void modify(int l,int r,int a,int b,int tl,int tr,int t)
{
//	if(t==1)printf("modify %d %d %d %d\n",l,r,a,b);
	if(l>r)return;
	if(l<=tl&&tr<=r)
	{
		seg[t].apply(a,b);
		return;
	}
	pushdown(t);
	int mid=(tl+tr)>>1;
	if(l<=mid)modify(l,r,a,b,tl,mid,ls);
	if(r>mid)modify(l,r,a,b,mid+1,tr,rs);
	seg[t].sum=(seg[ls].sum+seg[rs].sum)%mod;
}
int query(int l,int r,int tl,int tr,int t)
{
	if(l<=tl&&tr<=r)return seg[t].sum;
	pushdown(t);
	int mid=(tl+tr)>>1,ret=0;
	if(l<=mid)ret=(ret+query(l,r,tl,mid,ls))%mod;
	if(r>mid)ret=(ret+query(l,r,mid+1,tr,rs))%mod;
	return ret;
}

set<pii> ind[600111];

int n,q;
void add(set<pii>&st,int l,int r)
{
	auto it1=st.lower_bound(mp(l,0));
	int nl=l;
	if(it1!=st.begin())
	{
		it1--;
		if(it1->ss<l-1)
			it1++;
		else nl=it1->ff;
	}
	int last=l;
	for(;it1!=st.end()&&(it1->ff<=r+1&&it1->ss>=l-1);)
	{
		modify(max(l,it1->ff),min(r,it1->ss),2,0,1,n,1);
		if(last<it1->ff)modify(last,it1->ff-1,1,1,1,n,1);
		last=it1->ss+1;
		auto tmp=it1;it1++;
		st.erase(tmp);
	}
	if(last<=r){modify(last,r,1,1,1,n,1);last=r+1;}
	st.insert(mp(nl,last-1));
//	for(auto v:st)printf("segs= %d %d\n",v.ff,v.ss);
}

int main()
{
	get2(n,q);
	build(1,n,1);
	for(int i=1,op,l,r,v;i<=q;i++)
	{
		get3(op,l,r);
		if(op==1)
		{
			get1(v);
			add(ind[v],l,r);
		}
		else printf("%d\n",query(l,r,1,n,1));
	}
	return 0;
}