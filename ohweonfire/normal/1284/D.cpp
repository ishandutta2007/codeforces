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

const int maxn=100111;
const int maxv=1100111;
#define ls (t<<1)
#define rs ((t<<1)|1)
namespace sgt
{
	int mn[maxv],dlt[maxv];
	void push(int t)
	{
		if(dlt[t])
		{
			mn[ls]+=dlt[t];dlt[ls]+=dlt[t];
			mn[rs]+=dlt[t];dlt[rs]+=dlt[t];
			dlt[t]=0;
		}
	}
	void pull(int t)
	{
		mn[t]=min(mn[ls],mn[rs]);
	}
	void add(int l,int r,int v,int tl,int tr,int t)
	{
//		if(t==1)printf("Add %d %d v= %d\n",l,r,v);
		if(l<=tl&&tr<=r)
		{
			mn[t]+=v;dlt[t]+=v;
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(l<=mid)add(l,r,v,tl,mid,ls);
		if(r>mid)add(l,r,v,mid+1,tr,rs);
		pull(t);
	}
	int query(int l,int r,int tl,int tr,int t)
	{
		if(l<=tl&&tr<=r)return mn[t];
		push(t);
		int mid=(tl+tr)>>1,ret=inf;
		if(l<=mid)ret=min(ret,query(l,r,tl,mid,ls));
		if(r>mid)ret=min(ret,query(l,r,mid+1,tr,rs));
		return ret;
	}
}

int sa[maxn],sb[maxn],ta[maxn],tb[maxn],n;
vector<int> vs;
int getid(int x){return upper_bound(vs.begin(),vs.end(),x)-vs.begin();}

vector<int> hsa[maxv],hsb[maxv],hta[maxv],htb[maxv];

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get2(sa[i],ta[i]);
		vs.pb(sa[i]);vs.pb(ta[i]);
		get2(sb[i],tb[i]);
		vs.pb(sb[i]);vs.pb(tb[i]);
	}
	sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=1;i<=n;i++)
	{
		sa[i]=getid(sa[i]);
		sb[i]=getid(sb[i]);
		ta[i]=getid(ta[i]);
		tb[i]=getid(tb[i]);
		hsa[sa[i]].pb(i);
		hsb[sb[i]].pb(i);
		hta[ta[i]].pb(i);
		htb[tb[i]].pb(i);
	}
	
	int sz=(int)vs.size();
	memset(sgt::mn,0,sizeof(sgt::mn));
	memset(sgt::dlt,0,sizeof(sgt::dlt));
	for(int i=1;i<=sz;i++)
	{
		for(auto v:hsa[i])
		{
			if(sgt::query(sb[v],tb[v],1,sz,1))
			{
				puts("NO");
				return 0;
			}
		}
		for(auto v:hta[i])sgt::add(sb[v],tb[v],-1,1,sz,1);
	}
	
	memset(sgt::mn,0,sizeof(sgt::mn));
	memset(sgt::dlt,0,sizeof(sgt::dlt));
	for(int i=1;i<=sz;i++)
	{
		for(auto v:hsb[i])
		{
			if(sgt::query(sa[v],ta[v],1,sz,1))
			{
				puts("NO");
				return 0;
			}
		}
		for(auto v:htb[i])sgt::add(sa[v],ta[v],-1,1,sz,1);
	}
	
	memset(sgt::mn,0,sizeof(sgt::mn));
	memset(sgt::dlt,0,sizeof(sgt::dlt));
	for(int i=sz;i>=1;i--)
	{
		for(auto v:hta[i])
		{
			if(sgt::query(sb[v],tb[v],1,sz,1))
			{
				puts("NO");
				return 0;
			}
		}
		for(auto v:hsa[i])sgt::add(sb[v],tb[v],-1,1,sz,1);
	}
	
	memset(sgt::mn,0,sizeof(sgt::mn));
	memset(sgt::dlt,0,sizeof(sgt::dlt));
	for(int i=sz;i>=1;i--)
	{
		for(auto v:htb[i])
		{
			if(sgt::query(sa[v],ta[v],1,sz,1))
			{
				puts("NO");
				return 0;
			}
		}
		for(auto v:hsb[i])sgt::add(sa[v],ta[v],-1,1,sz,1);
	}
	puts("YES");
	
	return 0;
}