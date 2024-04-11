#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m;
int a[MN],b[MN],c[MN];
ll v[MN],sv[MN];
ll f[MN],ans=infll;
ll val[MN];
ll bit[MN];
inline void Add(int i,ll x){for(;i<=n;i+=i&-i)bit[i]+=x;}
inline ll Qur(int i){ll s=0;for(;i;i-=i&-i)s+=bit[i];return s;}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)scanf("%lld",v+i),sv[i]=sv[i-1]+v[i];
	scanf("%d",&m);
	F(i,1,m)scanf("%d",b+i),c[b[i]]=i;{
		int j=1;
		F(i,1,n)if(j<=m&&a[i]==b[j])++j;
		if(j<=m)return puts("NO"),0;
		puts("YES");
	}
	F(i,1,m)f[i]=infll;
	F(i,1,n){
		if(c[a[i]]){
			int p=c[a[i]];
			val[i]=f[p-1]+sv[i-1]-Qur(b[p-1]);
			if(v[i]>0)Add(a[i],v[i]);
			f[p]=min(f[p],val[i]-sv[i]+Qur(b[p]));
		}else if(v[i]>0)Add(a[i],v[i]);
	}
	ll sum=0;
	dF(i,n,1){
		if(a[i]==b[m]){
			ans=min(ans,val[i]+sum);
			if(v[i]<0)sum+=v[i];
		}else if(a[i]>b[m]||v[i]<0)sum+=v[i];
	}
	printf("%lld\n",ans);
	return 0;
}