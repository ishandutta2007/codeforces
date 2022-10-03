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
#define mp make_pair
#define fi first
#define se second
int l,r;
inline ll f(int n1,int n2){
	if(n1<0||n2<0)return 0;
	static int b1[40],b2[40];
	F(j,0,30)b1[j]=n1>>j&1,b2[j]=n2>>j&1;
	ll f=0,g1=0,g2=0,o=1;//f:x1<n1,x2<n2, g1:x1=n1,x2<n2, g2:x1<n1,x2=n2
	dF(j,30,0){
		f*=3;
		if(b1[j])f+=g1*2;
		if(b2[j])f+=g2*2;
		if(b1[j]&&b2[j])f+=o;
		
		if(!b1[j])g1*=2;
		if(b2[j])g1+=o;
		
		if(!b2[j])g2*=2;
		if(b1[j])g2+=o;
		
		if(b1[j]&&b2[j])o=0;
	}
	return f+g1+g2+o;
}
int main(){int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&r);
		printf("%lld\n",f(r,r)-2*f(r,l-1)+f(l-1,l-1));
	}
	return 0;
}