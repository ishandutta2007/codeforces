#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int f[Maxn+5][2];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<=n;i++){
			f[i][0]=f[i][1]=Inf;
		}
		f[1][0]=a[1];
		f[2][0]=a[1]+a[2];
		f[2][1]=f[1][0];
		for(int i=3;i<=n;i++){
			f[i][0]=min(f[i][0],f[i-1][1]+a[i]);
			f[i][0]=min(f[i][0],f[i-2][1]+a[i-1]+a[i]);
			f[i][1]=min(f[i][1],f[i-1][0]);
			f[i][1]=min(f[i][1],f[i-2][0]);
		}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
	return 0;
}