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
inline int _lg(ll x){return 63-__builtin_clzll(x);}
ll n,k,ans;
inline ll calc(ll x){
	if(x<=0||x>n)return 0;
	int bn=_lg(n);
	int bx=_lg(x);
	ll o=x-(n>>(bn-bx)),num=0;
	if(o>0)num=(1ll<<(bn-bx))-1;
	else if(o<0)num=(2ll<<(bn-bx))-1;
	else num=(n&((1ll<<(bn-bx))-1))+(1ll<<(bn-bx));
	if(x%2==0)num+=calc(x+1);
	return num;
}
inline void upd(ll x){
	ll cnt=calc(x);
	if(cnt>=k&&x>=ans)ans=x;
}
int main(){
	scanf("%lld%lld",&n,&k);
	F(i,1,100)upd(i);
	F(i,0,61)upd((1ll<<i)-1),upd((1ll<<i)-2),upd((1ll<<i)-3);
	ll m=n;
	while(m)upd(m+3),upd(m+2),upd(m+1),upd(m),upd(m-1),upd(m-2),upd(m-3),m>>=1;
	printf("%lld\n",ans);
	return 0;
}