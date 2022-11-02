#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(LL i = a;i <= b;++i)
#define ROF(i,a,b) for(LL i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
LL a[MAXN];
int n,q;
LL sm = 0;

inline LL calc(){
	LL b1 = (a[1]-sm)/2;
	LL ans = 1e18;
	FOR(bb,b1-5,b1+5) ans = std::min(ans,std::max(b1+sm,a[1]-b1));
	return ans;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",a+i);
	ROF(i,n,1) a[i] -= a[i-1],sm += std::max(0ll,(i!=1)*a[i]);
	printf("%lld\n",calc());
	scanf("%d",&q);
	FOR(i,1,q){
		int l,r,x;scanf("%d%d%d",&l,&r,&x);
		sm -= std::max(0ll,(l!=1)*a[l]);
		a[l] += x;
		sm += std::max(0ll,(l!=1)*a[l]);
		if(r < n){
			sm -= std::max(0ll,a[r+1]);
			a[r+1] -= x;
			sm += std::max(0ll,a[r+1]);
		}
		printf("%lld\n",calc());
	}
	return 0;
}