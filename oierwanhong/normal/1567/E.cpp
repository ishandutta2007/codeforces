#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
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
/**********/
const int MAXN = 200011;
int n,a[MAXN];
	struct node
	{
		int lv,rv,lc,rc,len;
		ll res;
	}t[MAXN<<2|1];
	node operator+ (node tl,node tr)
	{
		ll res=tl.res+tr.res;
		if(tl.rv<=tr.lv)
		{
			res+=ll(tl.rc)*tr.lc;
			return node{tl.lv,tr.rv,
				tl.lc==tl.len?tl.lc+tr.lc:tl.lc,
				tr.rc==tr.len?tr.rc+tl.rc:tr.rc,tl.len+tr.len, res};
		}
		return node{tl.lv,tr.rv,tl.lc,tr.rc,tl.len+tr.len,res};
	}
namespace sgt
{
#define rt t[num]
	void init(un l=1,un r=n,un num=1)
	{
		if(l==r)rt={a[l],a[l],1,1,1,1ll};
		else
		{
			un mid=(l+r)>>1;
			init(l,mid,num<<1),init(mid+1,r,num<<1|1);
			rt=t[num<<1]+t[num<<1|1];
		}
	}
	void modify(un pos,int k,un l=1,un r=n,un num=1)
	{
		if(l==r){rt=node{k,k,1,1,1,1ll};return;}
		un mid=(l+r)>>1;
		if(pos<=mid)modify(pos,k,l,mid,num<<1);
		else modify(pos,k,mid+1,r,num<<1|1);
		rt=t[num<<1]+t[num<<1|1];
	}
	node Query(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt;
		un mid=(l+r)>>1;
		if(qr<=mid)return Query(ql,qr,l,mid,num<<1);
		if(ql>mid)return Query(ql,qr,mid+1,r,num<<1|1);
		return Query(ql,qr,l,mid,num<<1)+Query(ql,qr,mid+1,r,num<<1|1);
	}
}
int main()
{
	n=read();
	int m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sgt::init();
	while(m--)
	{
		int op=read();
		if(op==1){int x=read(),y=read();sgt::modify(x,y);}
		else
		{
			int l=read(),r=read();
			printf("%lld\n",sgt::Query(l,r).res);
		}
	}
	return 0;
}