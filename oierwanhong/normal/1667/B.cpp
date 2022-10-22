
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
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
const int MAXN = 1000011;
const ll LINF = 1ll<<60;
ll fx[MAXN];
int diff;
int place(ll val){return std::lower_bound(fx+1,fx+diff+1,val)-fx;}
struct BIT
{
	ll t[MAXN];
#define lowb (i&-i)
	void init()
	{
		for(int i=1;i<=diff;++i)t[i]=-LINF;
	}
	void modify(int i,ll k)
	{
		while(i<=diff)umax(t[i],k),i+=lowb;
	}
	ll Qmax(int i)
	{
		ll res=-LINF;
		while(i)umax(res,t[i]),i-=lowb;
		return res;
	}
}pre,suf;

ll sum[MAXN],f[MAXN],eq[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		diff=0;
		int n=read();
		fx[++diff]=0;
		for(int i=1;i<=n;++i)fx[++diff]= sum[i]=sum[i-1]+read();
		std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
		pre.init(),suf.init();
		for(int x=1;x<=diff;++x)eq[x]=-LINF;
		pre.modify(place(0),0);
		suf.modify(diff-place(0)+1,0);
		eq[place(0)]=0;
		for(int i=1;i<=n;++i)
		{
			f[i]=-LINF;
			int p=place(sum[i]);
			umax(f[i],pre.Qmax(p-1)+i);
			umax(f[i],suf.Qmax(diff-p)-i);
			umax(f[i],eq[p]);
			pre.modify(p,f[i]-i),umax(eq[p],f[i]),suf.modify(diff-p+1,f[i]+i);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}