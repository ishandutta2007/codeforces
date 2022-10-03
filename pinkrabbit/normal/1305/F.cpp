#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,c,ans;
ll a[MN],p[MN];
void chk(ll z){
	ll s=0;
	F(i,1,n){
		if(a[i]<z)s+=z-a[i];
		else s+=min(a[i]%z,z-a[i]%z);
		if(s>=ans)return;
	}
	ans=s;
}
int main(){
	scanf("%d",&n),ans=n;
	F(i,1,n)scanf("%lld",a+i);
	shuffle(a+1,a+n+1,rng);
	F(i,1,min(30,n)){
		ll z=a[i];
		for(ll i=2;i*i<=z;++i)if(z%i==0){p[++c]=i;while(z%i==0)z/=i;}if(z>1)p[++c]=z;
		z=a[i]-1;
		for(ll i=2;i*i<=z;++i)if(z%i==0){p[++c]=i;while(z%i==0)z/=i;}if(z>1)p[++c]=z;
		z=a[i]+1;
		for(ll i=2;i*i<=z;++i)if(z%i==0){p[++c]=i;while(z%i==0)z/=i;}if(z>1)p[++c]=z;
	}
	sort(p+1,p+c+1),c=unique(p+1,p+c+1)-p-1;
//	F(i,1,c)printf("%lld,",p[i]);puts("");
	F(i,1,c)chk(p[i]);
	printf("%d\n",ans);
	return 0;
}