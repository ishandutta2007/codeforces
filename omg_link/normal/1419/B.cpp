#include <stdio.h>
typedef long long LL;

LL n;

void solve(){
	scanf("%lld",&n);
	int ans = 0;
	for(LL i=2;;i<<=1){
		LL s = ((i-1)*i)>>1;
		if(n>=s){
			n -= s;
			ans++;
		}else{
			break;
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}