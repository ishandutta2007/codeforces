#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011;
int n;
struct Segment_Tree
{
	struct node
	{
		ll sum,tag;
	}t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void pushdown(un l,un r,un num)
	{
		if(!rt.tag)return;
		un mid=(l+r)>>1;
		tl.sum+=(mid-l+1)*rt.tag,tl.tag+=rt.tag;
		tr.sum+=(r-mid)*rt.tag,tr.tag+=rt.tag;
		rt.tag=0;
	}
	void pushup(un num){rt.sum=tl.sum+tr.sum;}
	void modify(un ql,un qr,int k,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr){rt.sum+=ll(k)*(r-l+1),rt.tag+=k;return;}
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		pushup(num);
	}
	ll Qsum(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt.sum;
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		ll res=0;
		if(ql<=mid)res+=Qsum(ql,qr,l,mid,num<<1);
		if(qr>mid)res+=Qsum(ql,qr,mid+1,r,num<<1|1);
		return res;
	}
}T;
struct one
{
	int l,r,v;
	one(){}
	one(int l,int r,int v):l(l),r(r),v(v) {}
	bool operator< (const one& you)const{return l<you.l;}
};
std::set<one>S;
int main()
{
	n=read();
	int m=read();
	S.insert(one(0,0,0)),S.insert(one(n+1,n+1,0));
	for(int i=1;i<=n;++i)S.insert(one(i,i,i));
	for(int w=1;w<=m;++w)
	{
		//printf("W=%d\n",w);
		int op=read(),l=read(),r=read();
		if(op==1)
		{
			int k=read();
			auto it=--S.lower_bound(one(l+1,0,0));
			std::vector<one>tp;
			while(it->l<=r)
			{
				if(it->l < l)tp.emplace_back(one(it->l,l-1,it->v));
				if(it->r > r)tp.emplace_back(one(r+1,it->r,it->v));
				int st=max(it->l,l),ed=min(it->r,r);
				T.modify(st,ed,abs(k-it->v));
				S.erase(it++);
			}
			S.insert(one(l,r,k));
			for(auto I:tp)S.insert(I);
		}
		else printf("%lld\n",T.Qsum(l,r));
		//if(w%100==0)fprintf(stderr,"W=%d\n",w);
	}
	return 0;
}