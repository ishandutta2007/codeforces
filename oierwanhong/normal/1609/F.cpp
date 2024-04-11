#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011;
ll a[MAXN];
int cnt[MAXN],suf[MAXN],premin[MAXN],premax[MAXN];
int f[60];
std::vector<pii>fmax[MAXN],fmin[MAXN];
ll ans=0;
inline bool Less(int x,int y){return a[x]<a[y]||(a[x]==a[y]&&x<y);}
inline void RealClear(std::vector<pii>& P)
{
	std::vector<pii>tp;
	P.swap(tp);
}
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	//printf("[%d,%d],preans=%lld\n",l,r,ans);
	for(int i=mid+1;i<=r;++i)fmax[i].clear(),fmax[i].shrink_to_fit(),fmin[i].clear(),fmin[i].shrink_to_fit();
	premin[mid+1]=premax[mid+1]=mid+1;
	for(int i=mid+2;i<=r;++i)premin[i]=Less(premin[i-1],i)?premin[i-1]:i,premax[i]=Less(premax[i-1],i)?i:premax[i-1];
	suf[r+1]=0;
	for(int i=r;i>mid;--i)
	{
		suf[i]=suf[i+1]+(cnt[premin[i]]==cnt[premax[i]]);
		//printf("i=%d,\n",i,suf[i]);
	}
	int j=mid+1,k=mid+1,minp=mid,maxp=mid;
	for(int i=mid;i>=l;--i)
	{
		if(a[i]<=a[minp])minp=i;
		if(a[i]>a[maxp])maxp=i;
		while(j<=r&&a[premax[j]]<a[maxp])++j;
		while(k<=r&&a[premin[k]]>=a[minp])++k;
		if(j<=k)fmax[k-1].emplace_back(pii(cnt[minp],1)),fmax[j-1].emplace_back(pii(cnt[minp],-1));
		else fmin[j-1].emplace_back(pii(cnt[maxp],1)),fmin[k-1].emplace_back(pii(cnt[maxp],-1));
		ans+= (cnt[minp]==cnt[maxp]?min(j,k)-mid-1:0)+suf[max(j,k)];
		//printf("i=%d,j=%d,k=%d (%d,%d)\n",i,j,k,(cnt[minp]==cnt[maxp]?min(j,k)-mid-1:0),suf[max(j,k)]);
	}
	//printf("Tpans=%lld\n",ans);
	for(int i=mid+1;i<=r;++i)
	{
		++f[cnt[premax[i]]];
		//printf("Incr %d\n",cnt[premax[i]]);
		for(auto x:fmax[i])
		{
			//nprintf("Obj (%d,%d)\n",x.first,x.second);
			if(x.second==1)ans+=f[x.first];
			else ans-=f[x.first];
		}
	}
	for(int i=mid+1;i<=r;++i)--f[cnt[premax[i]]];
	for(int i=mid+1;i<=r;++i)
	{
		++f[cnt[premin[i]]];
		for(auto x:fmin[i])
			if(x.second==1)ans+=f[x.first];
			else ans-=f[x.first];
	}
	for(int i=mid+1;i<=r;++i)--f[cnt[premin[i]]];
	//printf("Ans=%lld\n",ans);
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read(),cnt[i]=__builtin_popcountll(a[i]);
	solve(1,n);
	printf("%lld\n",ans+n);
	return 0;
}