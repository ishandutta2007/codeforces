#include <stdio.h>
#include <algorithm>
#define MN 200000
#define int LL
typedef long long LL;

const LL INF = 0x7fffffffffffffff;

int n,k;
int al,ar,bl,br;
int unlock,cost1;
LL ans;

LL check(int unlockNum){
	LL ret = 1ll*unlock*unlockNum;
	if(1ll*cost1*unlockNum>=k) return ret+k;
	int k = ::k;
	ret += 1ll*cost1*unlockNum;
	k -= 1ll*cost1*unlockNum;
	return ret + 2*k;
}

void solve(){
	scanf("%lld%lld",&n,&k);
	scanf("%lld%lld",&al,&ar);
	scanf("%lld%lld",&bl,&br);
	if(al>bl){
		std::swap(al,bl);
		std::swap(ar,br);
	}
	if(ar>=bl) unlock = 0;
	else unlock = bl-ar;
	cost1 = 2*(std::max(ar,br) - al) - ((ar-al) + (br-bl)) - unlock;
	k -= n*std::max(0ll,std::min(ar,br)-bl);
	//ans
	ans = INF;
	for(int i=1;i<=n;i++){
		LL tans = check(i);
		ans = std::min(ans,tans);
	}
	printf("%lld\n",std::max(ans,0ll));
}

signed main(){
	int T; scanf("%lld",&T);
	while(T--) solve();
}