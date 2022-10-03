#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n;ll ans;
int a[MN];
map<ll,int>mp;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	mp[0]=1;
	ll s=0;
	int lst=0;
	F(i,1,n){
		s+=a[i];
		lst=max(lst,mp[s]);
//		printf("%d : %d\n", i,lst);
		ans+=i-lst;
		mp[s]=i+1;
	}
	printf("%lld\n",ans);
	return 0;
}