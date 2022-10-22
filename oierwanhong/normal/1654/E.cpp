#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
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
const int MAXN = 500011,V = 2e5;
ll a[MAXN],b[MAXN],tp[MAXN],seq[MAXN];
int main()
{
	int n=read();
	if(n<=2){puts("0");return 0;}
	for(int i=1;i<=n;++i)a[i]=read(),b[i]=a[i];
	int ans=n,up=n;
	for(int d=0;d<=300;++d)
	{
		for(int i=1;i<=up;++i)seq[i]=a[i]-d*ll(i-1);
		std::sort(seq+1,seq+up+1);
		int maxl=1,cur=1;
		for(int i=2;i<=up;++i)
			if(seq[i]==seq[i-1])umax(maxl,++cur);
			else cur=1;
		umin(ans,n-maxl);
	}
	for(int d=0;d<=300;++d)
	{
		for(int i=1;i<=up;++i)seq[i]=a[i]+d*ll(i-1);
		std::sort(seq+1,seq+up+1);
		int maxl=1,cur=1;
		for(int i=2;i<=up;++i)
			if(seq[i]==seq[i-1])umax(maxl,++cur);
			else cur=1;
		umin(ans,n-maxl);
	}
	for(int i=1;i<=n;++i)
	{
		int l=0;
		for(int j=max(1,i-350);j<i;++j)
			if((a[i]-a[j])%(i-j)==0)seq[++l]=(a[i]-a[j])/(i-j);
		std::sort(seq+1,seq+l+1);
		int maxl=1,cur=1;
		for(int i=2;i<=l;++i)
			if(seq[i]==seq[i-1])umax(maxl,++cur);
			else cur=1;
		umin(ans,n-maxl-1);
	}
	printf("%d\n",ans);
	return 0;
}