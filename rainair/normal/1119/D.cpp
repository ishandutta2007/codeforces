#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int n,q;
LL a[MAXN],ans[MAXN],b[MAXN];
P qry[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",a+i);
	scanf("%d",&q);
	FOR(i,1,q){
		LL l,r;scanf("%lld%lld",&l,&r);
		qry[i] = MP(r-l+1,i);
	}
	std::sort(a+1,a+n+1);
	FOR(i,1,n-1) b[i] = a[i+1]-a[i];
	std::sort(b+1,b+n);
	int tp = 1;LL sm = 0;
	std::sort(qry+1,qry+q+1);
	FOR(i,1,q){
		while(tp <= n-1 && b[tp] <= qry[i].fi) sm += b[tp],++tp;
		ans[qry[i].se] = 1ll*(n+1-tp)*qry[i].fi+sm;
	}
	FOR(i,1,q) printf("%lld ",ans[i]);puts("");
	return 0;
}