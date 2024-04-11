#include <cstdio>
typedef long long ll;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll x;
		scanf("%lld",&x);
		int ans=0;
		ll sum=0;
		for(int i=1;sum+(((1ll<<i)-1)*((1ll<<i))>>1)<=x;i++){
			sum+=(((1ll<<i)-1)*((1ll<<i)))>>1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}