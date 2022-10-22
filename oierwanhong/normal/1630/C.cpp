#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 800011;
int n,ans;
struct Segment_Tree
{
	struct node
	{
		int tag;
		int sum;
	}t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void init(un l=1,un r=n,un num=1)
	{
		rt.tag=-1,rt.sum=0;
		if(l==r)return;
		un mid=(l+r)>>1;
		init(l,mid,num<<1),init(mid+1,r,num<<1|1);
	}
	void pushdown(un l,un r,un num)
	{
		if(rt.tag==-1)return;
		un mid=(l+r)>>1;
		tl.sum=(mid-l+1)*rt.tag,tl.tag=rt.tag;
		tr.sum=(r-mid)*rt.tag,tr.tag=rt.tag;
		rt.tag=-1;
	}
	void Cover(un ql,un qr,int k,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr){rt.tag=k,rt.sum=k*(r-l+1);return;}
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		if(ql<=mid)Cover(ql,qr,k,l,mid,num<<1);
		if(qr>mid)Cover(ql,qr,k,mid+1,r,num<<1|1);
		rt.sum=tl.sum+tr.sum;
	}
	int Qsum(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt.sum;
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		int res=0;
		if(ql<=mid)res+=Qsum(ql,qr,l,mid,num<<1);
		if(qr>mid)res+=Qsum(ql,qr,mid+1,r,num<<1|1);
		return res;
	}
}T;
int a[MAXN],fir[MAXN],pos[MAXN];
bool del[MAXN];
int main()
{
	n=read();
	T.init();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		if(!fir[x]){fir[x]=i,pos[i]=i;continue;}
		pos[i]=fir[x];
		T.Cover(pos[i],i,1);
	}
	int minf=1e9;
	for(int i=n;i;--i)
	{
		if(minf<=pos[i]||pos[i]==i)del[i]=1;
		else minf=pos[i];
	}
	int las1=0,las2=0,dec=0;
	for(int i=1;i<=n;++i)
	{
		if(del[i])continue;
		if(las2<pos[i])dec+=2,las1=0,las2=i;
		else if(las1<pos[i])++dec,las1=las2,las2=i;
		else las2=i;
	}
	printf("%d\n",T.Qsum(1,n)-dec);
	return 0;
}