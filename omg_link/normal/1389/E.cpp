#include <stdio.h>
#include <algorithm>
typedef long long LL;

LL m,d,w;

LL C2(LL x){
	return x*(x-1)/2;
}

LL gcd(LL a,LL b){
	return a%b==0?b:gcd(b,a%b);
}

void solve(){
	scanf("%lld%lld%lld",&m,&d,&w);
	LL lim = std::min(m,d);
	LL k = (d-1)%w;
	LL r = w/gcd(k,w);
	LL blockNum = lim/r;
	LL singleNum = lim%r;
	LL np0=r-singleNum,vp0=blockNum;
	LL np1=singleNum,vp1=blockNum+1;
	printf("%lld\n",np0*C2(vp0)+np1*C2(vp1));
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}