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
int n,m,d,a[MN],b[MN],ta,tb;
ll sa[MN],sb[MN];
int main(){
	scanf("%d%d%d",&n,&d,&m);
	F(i,1,n){
		int x;
		scanf("%d",&x);
		if(x<=m)a[++ta]=x;
		else b[++tb]=x;
	}
	sort(a+1,a+ta+1);
	sort(b+1,b+tb+1);
	dF(i,ta,1)sa[i]=sa[i+1]+a[i];
	dF(i,tb,1)sb[i]=sb[i+1]+b[i];
//	printf("%d, %d\n",ta,tb);
	if(!tb)return printf("%lld\n",sa[1]),0;
	ll ans=0;
	F(k,1,tb){
		ll lb=(ll)d*(k-1),rb=(ll)d*k;
		int left=tb-k;
		if(left>rb)continue;
		lb-=left,rb-=left;
		if(lb<0)lb=0;
		if(ta<lb)continue;
//		printf("k=%d\n",k);
		ans=max(ans,sa[lb+1]+sb[tb-k+1]);
	}
	printf("%lld\n",ans);
	return 0;
}