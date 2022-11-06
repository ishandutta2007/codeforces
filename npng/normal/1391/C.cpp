#include <cstdio>
const int Maxn=1000000;
const int Mod=1000000007;
int main(){
	int n;
	scanf("%d",&n);
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=1ll*ans*i%Mod;
	}
	int now=1;
	for(int i=1;i<n;i++){
		now=(now<<1)%Mod;
	}
	printf("%d\n",(ans-now+Mod)%Mod);
	return 0;
}