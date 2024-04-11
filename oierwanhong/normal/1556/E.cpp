#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 200011;
const ll INF = 1e18+233;
int n,m;
ll a[MAXN];
struct one
{
	ll maxv,minv;
	one(){}
	one(ll maxv,ll minv):maxv(maxv),minv(minv) {}
	one operator+ (one you){return one(max(maxv,you.maxv),min(minv,you.minv));}
};
namespace sgt
{
	one t[MAXN<<2|1];
#define rt t[num]
	void init(un l=1,un r=n,un num=1)
	{
		if(l==r){rt.maxv=rt.minv=a[l];return;}
		un mid=(l+r)>>1;
		init(l,mid,num<<1),init(mid+1,r,num<<1|1);
		rt=t[num<<1]+t[num<<1|1];
	}
	one Query(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt;
		un mid=(l+r)>>1;
		one res(-INF,INF);
		if(ql<=mid)res=res+Query(ql,qr,l,mid,num<<1);
		if(qr>mid)res=res+Query(ql,qr,mid+1,r,num<<1|1);
		return res;
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]-=read();
	for(int i=1;i<=n;++i)a[i]+=read();
	for(int i=1;i<=n;++i)a[i]+=a[i-1];
	sgt::init();
	while(m--)
	{
		int l=read(),r=read();
		if(a[r]-a[l-1]){puts("-1");continue;}
		one res=sgt::Query(l,r);
		res.maxv-=a[l-1],res.minv-=a[l-1];
		if(res.minv<0)puts("-1");
		else printf("%lld\n",res.maxv);
	}
	return 0;
}