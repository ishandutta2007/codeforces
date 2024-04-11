#include<cstdio>
int n,k;
long long a[200002],las;
long long ans=0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++){
		ans+=1ll*((a[i]+las)/k);
		if(a[i]<(a[i]+las)%k) ans++,las=0;
		else las=(a[i]+las)%k;
	}
	if(las) ans++;
	printf("%I64d\n",ans);
	return 0;
}