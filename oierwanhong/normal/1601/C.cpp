#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
ll read()
{
	 ll x=0;bool f=0;char c=getchar();
	 while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	 while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	 return f?-x:x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 1000011;
int n;
struct Segment_Tree
{
	struct node
	{
		int minv,tag;
	}t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void pushdown(un num)
	{
		if(!rt.tag)return;
		tl.minv+=rt.tag,tl.tag+=rt.tag;
		tr.minv+=rt.tag,tr.tag+=rt.tag;
		rt.tag=0;
	}
	void modify(un ql,un qr,int k,un l=1,un r=n+1,un num=1)
	{
		if(ql<=l&&r<=qr){rt.minv+=k,rt.tag+=k;return;}
		pushdown(num);
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		rt.minv=min(tl.minv,tr.minv);
	}
	int Qmin(){return t[1].minv;}
}sgt;
struct BIT
{
	int t[MAXN];
#define lowb (i&-i)
	void modify(int i,int k)
	{
		while(i<=n)t[i]+=k,i+=lowb;
	}
	int Qsum(int i)
	{
		int res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
}bt;
pii a[MAXN];
int b[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		n=read();
		int m=read();
		ll ans=0;
		for(int i=1;i<=n;++i)a[i]=pii(read(),i);
		std::sort(a+1,a+n+1);
		for(int i=n,j;i;i=j)
		{
			j=i;
			while(a[j].first==a[i].first)ans+=bt.Qsum(a[j].second),--j;
			j=i;
			while(a[j].first==a[i].first)bt.modify(a[j].second,1),--j;
		}
		for(int i=1;i<=n;++i)bt.modify(i,-1),sgt.modify(1,i,1);
		for(int i=1;i<=m;++i)b[i]=read();
		std::sort(b+1,b+m+1);
		int it=m;
		for(int i=n,j;i;i=j)
		{
			while(it&&b[it]>a[i].first)ans+=sgt.Qmin(),--it;
			j=i;
			while(a[j].first==a[i].first)sgt.modify(1,a[j].second,-1),--j;
			while(it&&b[it]==a[i].first)ans+=sgt.Qmin(),--it;
			j=i;
			while(a[j].first==a[i].first)sgt.modify(a[j].second+1,n+1,1),--j;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i)sgt.modify(i+1,n+1,-1);
	}
	return 0;
}