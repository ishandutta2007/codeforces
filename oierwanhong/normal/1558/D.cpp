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
const int MAXN = 400011,mod = 998244353;
int L;
namespace sgt
{
	int t[MAXN<<2|1];
#define rt t[num]
	void init(un l=1,un r=L,un num=1)
	{
		rt=r-l+1;
		if(l==r)return;
		un mid=(l+r)>>1;
		init(l,mid,num<<1),init(mid+1,r,num<<1|1);
	}
	void modify(un pos,int k,un l=1,un r=L,un num=1)
	{
		rt+=k;
		if(l==r)return;
		un mid=(l+r)>>1;
		if(pos<=mid)modify(pos,k,l,mid,num<<1);
		else modify(pos,k,mid+1,r,num<<1|1);
	}
	int Qkth(int k,un l=1,un r=L,un num=1)
	{
		if(l==r)return l;
		un mid=(l+r)>>1;
		if(k<=t[num<<1])return Qkth(k,l,mid,num<<1);
		else return Qkth(k-t[num<<1],mid+1,r,num<<1|1);
	}
	int Query(un pos,un l=1,un r=L,un num=1)
	{
		if(l==r)return rt;
		un mid=(l+r)>>1;
		if(pos<=mid)return Query(pos,l,mid,num<<1);
		else return Query(pos,mid+1,r,num<<1|1);
	}
}
ll fac[MAXN],inv[MAXN],Ifac[MAXN];
ll C(int n,int m){return fac[n]*Ifac[m]%mod*Ifac[n-m]%mod;}
void init()
{
	fac[0]=Ifac[0]=1;
	inv[1]=1;
	for(int i=2;i<MAXN;++i)inv[i]=ll(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<MAXN;++i)fac[i]=fac[i-1]*i%mod,Ifac[i]=Ifac[i-1]*inv[i]%mod;
}
bool level[MAXN];
int stk[MAXN],pos[MAXN];
pii a[MAXN];
int main()
{
	init();
	L=200001;
	sgt::init();
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=m;++i)a[i].first=read(),a[i].second=read();
		int len=n,le=n-1,top=0;
		for(int i=m;i;--i)
		{
			pos[i]=sgt::Qkth(a[i].second);
			if(!level[pos[i]+1])--le;
			level[pos[i]]=1;
			sgt::modify(pos[i],-1);
		}
		printf("%lld\n",C(n+le,n));

		for(int i=1;i<=m;++i)sgt::modify(pos[i],1),level[pos[i]]=0;
	}
	return 0;
}