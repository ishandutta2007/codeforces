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
const int MAXN = 300011,INF = 1.233e9;
int n,L;
int a[MAXN],b[MAXN];
struct Segment_Tree_Min
{
	int t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void init(int* a,un l=1,un r=n,un num=1)
	{
		if(l==r){rt=a[l];return;}
		un mid=(l+r)>>1;
		init(a,l,mid,num<<1),init(a,mid+1,r,num<<1|1);
		rt=min(tl,tr);
	}
	int Qmin(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt;
		un mid=(l+r)>>1;
		int res=INF;
		if(ql<=mid)umin(res,Qmin(ql,qr,l,mid,num<<1));
		if(qr>mid)umin(res,Qmin(ql,qr,mid+1,r,num<<1|1));
		return res;
	}
}Tmin;
struct Segment_Tree_Sum
{
	struct node
	{
		ll sum,tag;
	}t[MAXN<<2|1];
	void pushdown(un l,un r,un num)
	{
		if(rt.tag==0)return;
		un mid=(l+r)>>1;
		tl.sum=(mid-l+1)*rt.tag,tl.tag=rt.tag;
		tr.sum=(r-mid)*rt.tag,tr.tag=rt.tag;
		rt.tag=0;
	}
	void init(un l=1,un r=L,un num=1)
	{
		rt.sum=rt.tag=0;
		if(l==r)return;
		un mid=(l+r)>>1;
		init(l,mid,num<<1),init(mid+1,r,num<<1|1);
	}
	void Cover(un ql,un qr,ll k,un l=1,un r=L,un num=1)
	{
		if(ql<=l&&r<=qr){rt.sum=(r-l+1)*k,rt.tag=k;return;}
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		if(ql<=mid)Cover(ql,qr,k,l,mid,num<<1);
		if(qr>mid)Cover(ql,qr,k,mid+1,r,num<<1|1);
		rt.sum=tl.sum+tr.sum;
	}
	ll Qsum(un ql,un qr,un l=1,un r=L,un num=1)
	{
		if(ql<=l&&r<=qr)return rt.sum;
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		ll res=0;
		if(ql<=mid)res+=Qsum(ql,qr,l,mid,num<<1);
		if(qr>mid)res+=Qsum(ql,qr,mid+1,r,num<<1|1);
		return res;
	}
}Tsum;
struct one
{
	int l,r,dex;
};
std::vector<one>Q1[MAXN];
std::vector<pii>Q2[MAXN];
int s[MAXN],val[MAXN], top;
ll res[MAXN];
int main()
{
	n=read();
	int m=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	Tmin.init(a);
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		Q1[l%k].emplace_back(one{(l-1)/k+1,(l-1)/k+1+(r-l)/k,i});
	}
	for(int r=0;r<k;++r)
	{
		//[]printf("R=%d\n",r);
		L=0;
		for(int i=r?r:k;i<=n;i+=k)b[++L]=i,Q2[L].clear();
		for(auto x:Q1[r])
		{
			Q2[x.l].emplace_back(pii(x.r,x.dex));
			//printf("Add (%d,%d,%d)\n",x.l,x.r,x.dex);
		}
		top=0;
		s[0]=L+1;
		for(int i=L;i;--i)
		{
			int v=Tmin.Qmin(b[i],min(b[i]+k-1,n)),flag=0;
			//printf("i=%d,v=%d\n",i,v);
			while(top&&val[top]>v)
			{
				//printf("Set [%d,%d] to %d\n",i+1,s[top-1]-1,v);
				Tsum.Cover(i+1,s[top-1]-1,v),--top;
				flag=1;
			}
			//printf("Set [%d,%d] to %d\n",i,i,a[b[i]]);
			Tsum.Cover(i,i,a[b[i]]);
			if(flag)s[++top]=i+1,val[top]=v;
			s[++top]=i,val[top]=a[b[i]];
			for(auto x:Q2[i])res[x.second]=Tsum.Qsum(i,x.first);
		}
	}
	for(int i=1;i<=m;++i)printf("%lld\n",res[i]);
	return 0;
}