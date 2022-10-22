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
const ll LINF = 1.233e18;
ll sum[4][MAXN],g[MAXN],h[MAXN],suf[MAXN],tag[MAXN];
ll f[MAXN];
struct one
{
	int l,r;
	ll k;
};
void CDQ(std::vector<one> Q,int l,int r)
{
	if(l==r)
	{
		ll extra=LINF;
		for(auto I:Q)
		{
			if(I.l<=l&&I.r>=r)umin(extra,I.k);
		}
		umax(f[l],f[l-1]-extra),
		umax(f[l],g[l]-extra);
		//printf("F[%d]=%lld\n",l,f[l]);
		return;
	}
	std::vector<one>LQ,RQ;
	int mid=(l+r)>>1;
	ll extra=LINF;
	for(auto I:Q)
	{
		if(I.l<=l&&I.r>=r)umin(extra,I.k);
	}
	for(auto I:Q)
	{
		if(I.l<=l&&I.r>=r)continue;
		if(I.l<=mid)LQ.emplace_back(I);
		if(I.r>mid)RQ.emplace_back(I);
	}
	if(extra<LINF)LQ.emplace_back(one{l,mid,extra}),RQ.emplace_back(one{mid+1,r,extra});
	CDQ(LQ,l,mid);
	suf[mid]=max(f[mid-1],g[mid]);
	for(int i=mid-1;i>=l;--i)suf[i]=max(max(suf[i+1],f[i-1]),g[i]);
	//printf("Conquer[%d,%d]\n",l,r);
	//printf("Suf:");
	//for(int i=l;i<=mid;++i)printf("%lld ",suf[i]);
	//puts("");
	for(int i=mid+1;i<=r;++i)tag[i]=-LINF;
	umax(tag[r],suf[l]-extra);
	for(auto I:Q)
		if(I.l<=mid&&I.r>mid)umax(tag[min(I.r,r)],suf[max(I.l,l)]-I.k);
	for(int i=r;i>mid;--i)
	{
		if(i<r)umax(tag[i],tag[i+1]);
		umax(f[i],tag[i]);
	}
	CDQ(RQ,mid+1,r);
}
int main()
{
	int n=read();
	int m=read();
	for(int x=1;x<=3;++x)
		for(int i=1;i<=n;++i)sum[x][i]=sum[x][i-1]+read();
	for(int i=1;i<=n;++i)
	{
		g[i]=sum[1][i]-sum[2][i-1],h[i]=sum[3][n]-sum[3][i-1]+sum[2][i];
		//printf("H[%d]=%lld\n",i,h[i]);
	}
	std::vector<one>Q;
	for(int i=1;i<=m;++i){int l=read(),r=read(),k=read();Q.emplace_back(one{l,r,k});}
	ll ans=-LINF;
	memset(f,0xcf,sizeof f);
	CDQ(Q,1,n);
	for(int i=1;i<=n;++i)umax(ans,f[i]+h[i]);
	printf("%lld\n",ans);
	return 0;
}