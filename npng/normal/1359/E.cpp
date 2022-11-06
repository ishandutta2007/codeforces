#include <cstdio>
const int Maxn=500000;
const int Mod=998244353;
int quick_power(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
int frac[Maxn+5],inv_f[Maxn+5];
void init(){
	frac[0]=frac[1]=1;
	for(int i=2;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2);
	for(int i=Maxn-1;i>0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	inv_f[0]=1;
}
int C(int n,int m){
	if(n<m){
		return 0;
	}
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+C(n/i-1,k-1))%Mod;
	}
	printf("%d\n",ans);
	return 0;
}