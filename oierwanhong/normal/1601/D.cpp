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
int fx[MAXN],diff=0;
int place(int val){return std::lower_bound(fx+1,fx+diff+1,val)-fx;}
pii a[MAXN];
bool cmp(pii a,pii b){return ll(a.first)*a.second<ll(b.first)*b.second;}
struct Segment_Tree
{
	struct node
	{
		int maxv,tag;
	}t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void pushdown(un num)
	{
		if(!rt.tag)return;
		tl.maxv+=rt.tag,tl.tag+=rt.tag;
		tr.maxv+=rt.tag,tr.tag+=rt.tag;
		rt.tag=0;
	}
	void modify(un ql,un qr,int k,un l=1,un r=diff,un num=1)
	{
		if(ql<=l&&r<=qr){rt.maxv+=k,rt.tag+=k;return;}
		pushdown(num);
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		rt.maxv=max(tl.maxv,tr.maxv);
	}
	int Qmax(un ql,un qr,un l=1,un r=diff,un num=1)
	{
		if(ql<=l&&r<=qr)return rt.maxv;
		pushdown(num);
		un mid=(l+r)>>1;
		int res=0;
		if(ql<=mid)umax(res,Qmax(ql,qr,l,mid,num<<1));
		if(qr>mid)umax(res,Qmax(ql,qr,mid+1,r,num<<1|1));
		return res;
	}
}sgt;
int main()
{
	int n=read(),lim=read(),nxt=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		if(x<lim)continue;
		fx[++diff]=x,fx[++diff]=y;
		a[++nxt]=pii(x,y);
	}
	n=nxt;
	std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
	for(int i=1;i<=n;++i)a[i].first=place(a[i].first),a[i].second=place(a[i].second);
	std::sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		int x=a[i].first,y=a[i].second;
		if(x<=y)
		{
			int f=sgt.Qmax(y,y);
			sgt.modify(y,y,sgt.Qmax(1,x)+1-f);
		}
		else
		{
			int f=sgt.Qmax(y,y);
			sgt.modify(y,y,sgt.Qmax(1,y)+1-f);
			if(y+1<=x)sgt.modify(y+1,x,1);
		}
	}
	printf("%d\n",sgt.Qmax(1,diff));
	return 0;
}