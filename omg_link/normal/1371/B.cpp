#include <stdio.h>
typedef long long LL;
int n,r;
LL ans;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&r);
		ans = 0;
		if(r >= n){
			ans++;
			r = n - 1;
		}
		ans += 1ll*r*(r+1)/2;
		printf("%lld\n",ans);
	}
}