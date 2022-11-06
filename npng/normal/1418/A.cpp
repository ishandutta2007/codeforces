#include <cstdio>
typedef long long ll;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		ll ans=1ll*k*y+k;
		ans--;
		printf("%lld\n",(ans+(x-1)-1)/(x-1)+k);
	}
	return 0;
}