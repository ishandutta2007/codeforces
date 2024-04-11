#include <cstdio>
const int Maxn=2000000;
const int Mod=1000000007;
int f[Maxn+5];
void init(){
	f[1]=f[2]=0;
	f[3]=f[4]=1;
	f[5]=3;
	for(int i=6;i<=Maxn;i++){
		if(i%3==0){
			f[i]=(1+4ll*f[i-4]+4ll*f[i-3]+f[i-2])%Mod;
		}
		else{
			f[i]=(f[i-1]+2ll*f[i-2])%Mod;
		}
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",4ll*f[n]%Mod);
	}
	return 0;
}