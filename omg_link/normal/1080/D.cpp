#include <stdio.h>
typedef long long LL;
int n; LL k,l,r;
LL calc(LL cnt,LL m){
	if(cnt<0) return 0;
	if(m>60) return 1e18;
	LL ret=0,bsc=1;
	for(LL i=0;i<m;i++){
		ret+=bsc;
		bsc<<=2;
	}
	double tmp=cnt;
	tmp*=ret;
	if(tmp>1e18) return 1e18;
	return cnt*ret;
}
void solve(){
	scanf("%d%lld",&n,&k);
	l=0,r=0;
	LL bl=2;
	for(int i=n-1;i>=0;i--){
		l+=bl-1; r+=bl-1;
		if(r<=k) r+=calc(2*bl-3,i);
		if(bl<=1e18) bl<<=1;
		if(l>k) break;
		if(l<=k&&k<=r){
			printf("YES %d\n",i);
			return;
		}
	}
	puts("NO");
}
int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}