//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
struct SegmentTree{
	ll lo[N<<2],hi[N<<2],val[N<<2],sval[N<<2],pd[N<<2],mnv[N<<2];
	void build(int x,int l,int r)
	{
		lo[x]=l,hi[x]=r,val[x]=sval[x]=pd[x]=mnv[x]=0;
		if(l==r) return;
		int mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void push_down(int x)
	{
		int a=x<<1;
		ll v=pd[x];
		val[a]+=v*(hi[a]-lo[a]+1),sval[a]+=v*(hi[a]-lo[a]+1)*(hi[a]+lo[a])/2,mnv[a]+=v,pd[a]+=v;
		val[a|1]+=v*(hi[a|1]-lo[a|1]+1),sval[a|1]+=v*(hi[a|1]-lo[a|1]+1)*(hi[a|1]+lo[a|1])/2,mnv[a|1]+=v,pd[a|1]+=v;
		pd[x]=0;
		return;
	}
	void update(int x,int l,int r,ll v)
	{
		int tl=lo[x],tr=hi[x];
		if(tl<tr&&pd[x]) push_down(x);
		if(l<=tl&&tr<=r)
		{
			pd[x]+=v,val[x]+=v*(tr-tl+1),sval[x]+=v*(tr-tl+1)*(tr+tl)/2,mnv[x]+=v;
			if(tl<tr) push_down(x);
			return;
		}
		int mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l) update(a,l,r,v);
		if(mid<r) update(a|1,l,r,v);
		val[x]=val[a]+val[a|1],sval[x]=sval[a]+sval[a|1],mnv[x]=min(mnv[a],mnv[a|1]);
		return;
	}
	int fd(int x,int v)
	{
		int tl=lo[x],tr=hi[x];
		if(tl==tr) return tl;
		if(pd[x]) push_down(x);
		int mid=(tl+tr)>>1,a=x<<1;
		if(mnv[a|1]>v) return fd(a,v);
		return fd(a|1,v);
	}
	ll qry1(int x,int l,int r)
	{
		int tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r) return val[x];
		if(pd[x]) push_down(x);
		int mid=(tl+tr)>>1,a=x<<1;
		ll ret=0;
		if(mid>=l) ret+=qry1(a,l,r);
		if(mid<r) ret+=qry1(a|1,l,r);
		return ret;
	}
	ll qry2(int x,int l,int r)
	{
		int tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r) return sval[x];
		if(pd[x]) push_down(x);
		int mid=(tl+tr)>>1,a=x<<1;
		ll ret=0;
		if(mid>=l) ret+=qry2(a,l,r);
		if(mid<r) ret+=qry2(a|1,l,r);
		return ret;
	}
}segt;
ll n,m,q,a[110],b[N];
int main(){
	ll tp,k,d,fstb;
	n=rint(),m=rint(),q=rint();
	for(int i=1;i<=n;++i) a[i]=rint();
	for(int i=1;i<=m;++i) b[i]=rint();
	fstb=b[2]-b[1];
	segt.build(1,1,m);
	for(int i=1;i<m;++i) segt.update(1,i,i,b[i+1]-b[i]);
	segt.update(1,m,m,LINF);
	while(q--)
	{
		tp=rint(),k=rint(),d=rint();
		if(tp==1) for(int i=n-k+1;i<=n;++i) a[i]+=d*(i-n+k);
		else
		{
			segt.update(1,m-k,m-1,d);
			if(k==m) b[1]+=d;
			if(k>=m-1) fstb+=d;
		}
		ll ans=0;
		int lst=1;
		for(int i=1;i<n;++i)
		{
			int x=segt.fd(1,a[i+1]-a[i]);
			x+=(x>1||fstb<=a[i+1]-a[i]);
			ans+=(x-lst+1)*(a[i]+b[1]);
			if(x>lst)
			{
				ll v1=segt.qry1(1,lst,x-1),v2=segt.qry2(1,lst,x-1);
				ans+=(n-i+m)*v1-v2;
			}
			lst=x;
		}
		ans+=(m-lst+1)*(a[n]+b[1]);
		if(m>lst)
		{
			ll v1=segt.qry1(1,lst,m-1),v2=segt.qry2(1,lst,m-1);
			ans+=m*v1-v2;
		}
		rout(ans),putchar('\n');
	}
	return 0;
}