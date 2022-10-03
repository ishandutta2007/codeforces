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
int n;
int a[MN],c[MN];
ll b1[MN],b2[MN];
inline void add(ll*b,int i,ll x){for(;i<=n;i+=i&-i)b[i]+=x;}
inline ll qur(ll*b,int i){ll a=0;for(;i;i-=i&-i)a+=b[i];return a;}
inline int bs(ll*b,ll x){
	int i=0;
	dF(j,19,0)if((i|1<<j)<=n){if(b[i|1<<j]<=x)x-=b[i|=1<<j];}
	return i;
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),c[a[i]]=i;
	ll cnt=0;
	F(i,1,n){
		int p=c[i];
		add(b1,p,1);
		cnt+=i-qur(b1,p);
		add(b2,p,p);
		int pos=bs(b1,i/2)+1;
//		printf("%lld,%d\n",cnt,pos);
		ll sum=0;
		ll aa=i/2,bb=i-i/2-1;
		sum+=(ll)aa*pos-(ll)aa*(aa+1)/2-qur(b2,pos-1);
		sum+=(qur(b2,n)-qur(b2,pos))-(ll)bb*pos-(ll)bb*(bb+1)/2;
		printf("%lld\n",sum+cnt);
	}
	return 0;
}