#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MS (1<<18|7)
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,q;
ll a[MN];
#define li (i<<1)
#define ri (li|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
ll s[MS];
void Build(int i,int l,int r){
	if(l==r)return s[i]=max(a[l],0ll),void();
	Build(ls),Build(rs);
	s[i]=s[li]+s[ri];
}
void Mdf(int i,int l,int r,int p,int x){
	if(l==r)return a[p]+=x,s[i]=max(a[p],0ll),void();
	p<=mid?Mdf(ls,p,x):Mdf(rs,p,x);
	s[i]=s[li]+s[ri];
}
inline ll solve(){
	ll x=s[1]-infll;
	return (x+(x&1))/2;
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%lld",a+i);
	a[0]=-infll;
	dF(i,n,1)a[i]-=a[i-1];
	Build(1,1,n);
	printf("%lld\n",solve());
	scanf("%d",&q);
	F(i,1,q){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		Mdf(1,1,n,l,x);
		if(r<n)Mdf(1,1,n,r+1,-x);
		printf("%lld\n",solve());
	}
	return 0;
}