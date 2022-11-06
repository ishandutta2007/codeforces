#include <cstdio>
int abs(int a){
	return a<0?-a:a;
}
typedef long long ll;
const int Maxn=100000;
int n;
int a[Maxn+5];
ll x[Maxn+5],y[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1){
		puts("1 1");
		printf("%d\n",-a[1]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=-a[i];
	}
	for(int i=1;i<n;i++){
		y[i]=(n-a[i]%n)%n;
		x[i]=(a[i]+y[i])/n-y[i];
	}
	printf("%d %d\n",1,n);
	for(int i=1;i<n;i++){
		printf("%lld ",1ll*x[i]*n);
	}
	puts("0");
	printf("%d %d\n",1,n-1);
	for(int i=1;i<n;i++){
		printf("%lld ",1ll*y[i]*(n-1));
	}
	puts("");
	printf("%d %d\n",n,n);
	printf("%d\n",a[n]);
	return 0;
}