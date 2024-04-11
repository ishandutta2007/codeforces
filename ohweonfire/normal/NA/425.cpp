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

const int maxn=500111;
const int maxv=2100111;
#define ls (t<<1)
#define rs ((t<<1)|1)
namespace sgt
{
	int mn[maxv],mncnt[maxv],dlt[maxv];
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
		mn[t]=min(mn[ls],mn[rs]);mncnt[t]=0;
		if(mn[ls]==mn[t])mncnt[t]+=mncnt[ls];
		if(mn[rs]==mn[t])mncnt[t]+=mncnt[rs];
	}
	void setv(int p,int v,int tl,int tr,int t)
	{
		if(tl==tr)
		{
			mncnt[t]=v;
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(p<=mid)setv(p,v,tl,mid,ls);
		else setv(p,v,mid+1,tr,rs);
		pull(t);
	}
	void modify(int l,int r,int v,int tl,int tr,int t)
	{
//		if(t==1)printf("Add %d %d v= %d\n",l,r,v);
		if(l<=tl&&tr<=r)
		{
			mn[t]+=v;dlt[t]+=v;
			return;
		}
		push(t);
		int mid=(tl+tr)>>1;
		if(l<=mid)modify(l,r,v,tl,mid,ls);
		if(r>mid)modify(l,r,v,mid+1,tr,rs);
		pull(t);
	}
	int query()
	{
//		printf("mn= %d\n",mn[1]);
		if(mn[1]==1)return mncnt[1];
		else return 0;
	}
}
int MX=1000001;
int n,q,a[maxn];
int main()
{
	get2(n,q);for(int i=1;i<=n;i++)get1(a[i]);
	a[0]=MX;a[n+1]=0;
	
	for(int i=0;i<=n;i++)sgt::modify(min(a[i],a[i+1])+1,max(a[i],a[i+1]),1,1,MX,1);
	for(int i=1;i<=n;i++)sgt::setv(a[i]+1,1,1,MX,1);
//	printf("hehe %d\n",sgt::query());
	for(int i=1,pos,v;i<=q;i++)
	{
		scanf("%d%d",&pos,&v);
		sgt::setv(a[pos]+1,0,1,MX,1);
		sgt::modify(min(a[pos-1],a[pos])+1,max(a[pos-1],a[pos]),-1,1,MX,1);
		sgt::modify(min(a[pos],a[pos+1])+1,max(a[pos],a[pos+1]),-1,1,MX,1);
		a[pos]=v;
		sgt::setv(a[pos]+1,1,1,MX,1);
		sgt::modify(min(a[pos-1],a[pos])+1,max(a[pos-1],a[pos]),1,1,MX,1);
		sgt::modify(min(a[pos],a[pos+1])+1,max(a[pos],a[pos+1]),1,1,MX,1);
		printf("%d\n",sgt::query());
	}
	return 0;
}