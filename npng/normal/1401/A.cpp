#include <cstdio>
const int Maxn=1000000;
int n,k;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(n<=k){
			printf("%d\n",k-n);
		}
		else{
			if((n&1)==(k&1)){
				puts("0");
			}
			else{
				puts("1");
			}
		}
	}
	return 0;
}