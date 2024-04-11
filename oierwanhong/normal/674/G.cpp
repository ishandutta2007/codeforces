#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
pii tp[12];
	struct node
	{
		pii a[6];
		int tag;
		node(){a[0]=a[1]=a[2]=a[3]=a[4]=pii(0,0),tag=0;}
		void pushtag(int k,int l){a[0]=pii(l,k);a[1]=a[2]=a[3]=a[4]=pii(0,0);tag=k;}
	};
int n;
bool cmp_sec(pii a,pii b){return a.second<b.second;}
namespace sgt
{
	node t[MAXN<<2|1];
#define rt t[num]
	void pushdown(un l,un r,un num)
	{
		if(!rt.tag)return;
		un mid=(l+r)>>1;
		t[num<<1].pushtag(rt.tag,mid-l+1),t[num<<1|1].pushtag(rt.tag,r-mid);
		rt.tag=0;
	}
	node merge(node tl,node tr)
	{
		node res;
		res.tag=0;
		for(int i=0;i<6;++i)tp[i]=tl.a[i],tp[6+i]=tr.a[i];
		std::sort(tp,tp+12,cmp_sec);
		int nl=0;
		for(int i=1;i<12;++i)
			if(tp[i].second==tp[nl].second)tp[nl].first+=tp[i].first;
			else tp[++nl]=tp[i];
		std::sort(tp,tp+nl+1),std::reverse(tp,tp+nl+1);
		while(nl>=6)
		{
			if(tp[nl].first)
				for(int x=0;x<nl;++x)tp[x].first=max(0,tp[x].first-tp[nl].first);
			tp[nl]=pii(0,0);
			--nl;
		}
		for(int i=0;i<=nl;++i)res.a[i]=tp[i],tp[i]=pii(0,0);
		for(int i=nl+1;i<6;++i)res.a[i]=pii(0,0);
		for(int i=0;i<12;++i)tp[i]=pii(0,0);
		return res;
	}
	void modify(un ql,un qr,int k,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt.pushtag(k,r-l+1);
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		rt=merge(t[num<<1],t[num<<1|1]);
	}
	node Query(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt;
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		node res;
		if(ql<=mid)res=merge(res,Query(ql,qr,l,mid,num<<1));
		if(qr>mid)res=merge(res,Query(ql,qr,mid+1,r,num<<1|1));
		return res;
	}
}
int main()
{
	n=read();
	int m=read(),p=read();
	for(int i=1;i<=n;++i)sgt::modify(i,i,read());
	while(m--)
	{
		int op=read(),l=read(),r=read();
		if(op==1)sgt::modify(l,r,read());
		else
		{
			int lim=(ll(p)*(r-l+1)+99)/100;
			node res=sgt::Query(l,r);
			int t=0;
			for(int i=0;i<6;++i)
				if(res.a[i].first)++t;
			printf("%lld ",min(100/p,t));
			for(int i=0;i<min(100/p,t);++i)
				if(res.a[i].first)printf("%d ",res.a[i].second);
			puts("");
		}
	}
	return 0;
}