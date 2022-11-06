#include <cstdio>
#include <cstring>
typedef long long ll;
const int Maxn=500000;
const int Mod=1000000007;
int n;
ll x[Maxn+5];
int num[65];
int pow_2[65];
void init(){
	pow_2[0]=1;
	for(int i=1;i<60;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
void solve(){
	memset(num,0,sizeof num);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		for(int j=0;j<60;j++){
			if((x[i]>>j)&1){
				num[j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum_and=0,sum_or=0;
		for(int j=0;j<60;j++){
			if((x[i]>>j)&1){
				sum_or=(sum_or+1ll*pow_2[j]*n)%Mod;
				sum_and=(sum_and+1ll*pow_2[j]*num[j])%Mod;
			}
			else{
				sum_or=(sum_or+1ll*pow_2[j]*num[j])%Mod;
			}
		}
		ans=(ans+1ll*sum_and*sum_or)%Mod;
	}
	printf("%d\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}