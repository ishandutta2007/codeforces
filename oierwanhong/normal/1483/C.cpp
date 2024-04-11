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
const int MAXN = 300011;
const ll INF=1e18;
int n;
namespace sgt
{
	struct node{ll maxv,tag;}t[MAXN<<2|1];
#define rt t[num]
#define tl t[num<<1]
#define tr t[num<<1|1]
	void pushdown(un num)
	{
		tl.maxv+=rt.tag,tl.tag+=rt.tag;
		tr.maxv+=rt.tag,tr.tag+=rt.tag;
		rt.tag=0;
	}
	void modify(un ql,un qr,ll k,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr){rt.maxv+=k,rt.tag+=k;return;}
		pushdown(num);
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		rt.maxv=max(tl.maxv,tr.maxv);
	}
	ll Qmax(un ql,un qr,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)return rt.maxv;
		pushdown(num);
		un mid=(l+r)>>1;
		ll res=-INF;
		if(ql<=mid)umax(res,Qmax(ql,qr,l,mid,num<<1));
		if(qr>mid)umax(res,Qmax(ql,qr,mid+1,r,num<<1|1));
		return res;
	}
}
int h[MAXN],b[MAXN],tp[MAXN], s[MAXN],top=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)h[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	sgt::modify(1,1,b[1]);
	int minh=h[1];
	ll g=b[1];
	for(int i=2;i<=n;++i)
	{
		while(top&&h[s[top]+1]>=h[i])
		{
			sgt::modify(s[top-1]+1,s[top],-b[s[top]+1]),--top;
		}
		sgt::modify(s[top]+1,i-1,b[i]);
		s[++top]=i-1;//,sgt::modify(i-1,i-1,b[i]);
		ll f=sgt::Qmax(1,i-1);
		if(h[i]<minh)minh=h[i],g=b[i];
		umax(f,g);
		sgt::modify(i,i,f);
	}
	printf("%lld\n",sgt::Qmax(n,n));
	return 0;
}