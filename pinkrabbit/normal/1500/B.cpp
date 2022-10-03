#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define MM 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int exGcd(int a,int b,int&x,int&y){
	if(!b)return x=1,y=0,a;
	int d=exGcd(b,a%b,y,x);
	return y-=a/b*x,d;
}
int n,m,g;
ll k;
int A[MM],B[MM];
vector<ll>C;
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	int w;
	F(i,1,n)scanf("%d",&w),A[w]=i;
	F(i,1,m)scanf("%d",&w),B[w]=i;
	int in,im;
	g=exGcd(n,m,in,im);
	ll lcm=(ll)n*m/g;
	F(i,1,2*max(n,m))if(A[i]&&B[i]){
		int x=A[i]-1,y=B[i]-1;
		if(x%g!=y%g)continue;
		ll z=(x+(ll)in*((y-x)/g)%m*n)%lcm;
		z=(z+lcm)%lcm;
		C.pb(z);
	}
	ll lb=1,rb=1e18,ans=0;
	while(lb<=rb){
		ll mid=(lb+rb)/2;
		ll days=mid;
		for(ll x:C)days-=(mid/lcm)+(x<(mid%lcm));
		if(days>=k)ans=mid,rb=mid-1;
		else lb=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}