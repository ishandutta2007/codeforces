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
const int MAXN = 600011;
ll a[MAXN],b[MAXN],tp[MAXN];
int n,m;
int get_state(int x,int y)//x<=y
{
	ll sum=0;
	int nxt=0;
	for(int i=1;i<=n;++i)
		if(b[i]<y)sum+=b[i]/x;
		else tp[++nxt]=b[i]/x;
	if(sum)return 1;
	ll cur=0;
	int sgn=1;
	for(int i=nxt;i;--i,sgn=-sgn)
	{
		if(sgn==1)--cur;
		else cur+=tp[i];
	}
	bool b= cur>=0;
	cur=0;
	sgn=-1;
	for(int i=nxt;i;--i,sgn=-sgn)
	{
		if(sgn==1)--cur;
		else cur+=tp[i];
	}
	bool a= cur>0;
	if(a)return b?1:3;
	else return b?4:2;
}
ll ans[7];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int s=2;s<=m+m;++s)
	{
		for(int i=1;i<=n;++i)b[i]=a[i]%s;
		std::sort(b+1,b+n+1);
		int l=max(s-m,1),r=min(s>>1,s-1);
		//printf("S=%d,lim[%d,%d]\n",s,l,r);
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(get_state(mid,s-mid)==1)l=mid;
			else r=mid-1;
		}
		int p=l;
		//printf("p=%d\n",p);
		int now=get_state(p,s-p);
		if(now!=1)
		{
			ans[now]+=(s-p)-p+1;
			continue;
		}
		int low=max(s-m,1);
		ans[1]+=p-low+1,ans[2]+=p-low+1;
		if(2*p<s)ans[get_state(p+1,s-p-1)]+= (s-p)-p-1;
	}
	printf("%lld %lld %lld %lld\n",ans[1],ans[2],ans[3],ans[4]);
	return 0;
}