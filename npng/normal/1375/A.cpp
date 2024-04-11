#include <cstdio>
int abs(int a){
	return a<0?-a:a;
}
const int Maxn=100;
int n;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			if(i&1){
				printf("%d ",-abs(a[i]));
			}
			else{
				printf("%d ",abs(a[i]));
			}
		}
		puts("");
	}
	return 0;
}